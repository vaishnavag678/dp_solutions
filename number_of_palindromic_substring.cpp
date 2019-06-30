//number of palindromic substring in given string 

class Solution {
    int dp[1005][1005];
    
    int go(int x,int y,string &s)
    {
        if(x>=y)
            return 1;
        int &ans=dp[x][y];
        if(ans!=-1)
            return ans;
        if(s[x]!=s[y])
            return ans=0;
        return ans=go(x+1,y-1,s);
        
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                ans+=go(i,j,s);
            }
        }
        return ans;
    }
};