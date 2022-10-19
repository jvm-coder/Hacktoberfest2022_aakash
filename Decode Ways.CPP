class Solution {
public:
    vector<int> dp;
    int decode(int m, int n,string s)
    {
		//if the substring starting index exceeds length of string
        if(m >= n)
            return 1;
        
		//if it is already calculated
        if(dp[m] != -1)
        {
            return dp[m];
        }
        
        int num = 0;
        int count = 0;
        
		//from the index given, calculated the no of ways..
        for(int i=m;i<n;i++)
        {
			//current digit + prev digit*10
            num = num*10 + (s[i] - '0');
			
			//if it is in range then its a possibity
            if(num>=1 && num<=26)
            {
			//add to count the no. of ways we can decode a smaller string
                count += decode(i+1,n,s);
            }
            else
            {
                break;
            }
        }
		
		//save and return
        dp[m] = count;
        return count;
    }
    int numDecodings(string s) {
        
         int n =s.length();
        
		//populate the dp table 
        for(int i=0;i<n;i++)
            dp.push_back(-1);
       
	   
        return decode(0,n,s);
    }
};
