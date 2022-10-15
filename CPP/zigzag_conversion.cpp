/*Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        vector<string> ans(min(numRows,int(s.length())));
        
        int curr=0;
        bool zig=false;
        for(int i=0;i<s.length();i++)
        {
            ans[curr]+=s[i];
            if(curr==0 || curr== numRows-1)
            {
                zig=!zig;
            }
            if(zig)
            {
                curr+=1;
            }
            else
            {
                curr-=1;
            }
        }
        string str;
        for(int i=0;i<ans.size();i++)
        {
            str+=ans[i];
        }
        return str;
    }
};
