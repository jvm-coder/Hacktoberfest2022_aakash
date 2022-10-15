<head>
    <title>COUNTING NO. OF WORDS</title>
    <style>
        body{
            background:linear-gradient(-45deg,black,rgba(80, 76, 76, 0.993),rgb(106, 106, 11),rgba(136, 128, 128, 0.63),rgba(87, 83, 83, 0.993),rgb(143, 143, 49));
            font-family: 'Courier New', Courier, monospace;
        }
        div{
            padding-top:1rem;
            border-radius:10px;
            border:5px solid black;
            width:80%;
            box-shadow: 5px 10px 8px 10px #2c2b2b;
            margin-top: 10rem;
        }
        button{
            height:2.5rem;
            width:6rem;
            margin:1rem;
            border-radius:10px;
            border:2px solid black;
            background-color: black;
            color:wheat;
            text-align: center;
            cursor: pointer;
        }
        button:hover{
            background-color: brown;
            color:yellow;
        }
        h2{
            display: inline-block;
            padding-right: 1rem;
            text-align: center;
        }
    </style>
</head>
<body>
    <center>
    <div>
        <h2>
<?php
$file1=$_REQUEST["file1"];
$file2=$_REQUEST["file2"];
$n1=filesize($file1);
$fp1=fopen($file1,'r');
$fp2=fopen($file2,'w');
$data=fread($fp1,$n1);
echo "<h2>CONTENT OF INPUT FILE : $data <br/>";
echo "THE WORDS ARE :";
CountWords($data,$fp2);
fclose($fp1);
fclose($fp2);
function printWords($n,$start,$end,$fp2){
    echo "<br/>";
    echo substr($n,$start,$end-$start+1);
    fwrite($fp2,substr($n,$start,$end-$start+1));
    fwrite($fp2,"\n");
}
function CountWords($n,$fp2){
    $cntwords=0;
    $len=strlen($n);
    $nl=strtolower($n);
    for($i=0;$i<$len;$i++){
        $start=$i;
        while(($nl[$i]>='a' && $nl[$i]<='z' )|| $nl[$i]=='_' || $nl[$i]=='-' || $nl[$i]=='\'')
        {
           $i++;
            if($i>=$len){
                break;
            }
        }
        if($start!=$i){
            printWords($n,$start,$i-1,$fp2);
            $cntwords++;
        }
    }
    echo "<br/>No. of Words : ".$cntwords."</h2>";
}

?>
</h2>
<br/>
<a href="WC.html"><button>BACK</button></a>
</div>
</center>
</body>
</html>