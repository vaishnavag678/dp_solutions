class Solution {
    int dp[1005][1005];
    
    int go(int x,int y,string &s)
    {
        if(x>y)
            return 0;
        if(x==y)
            return 1;
        int &ans=dp[x][y];
        if(ans!=-1)
            return ans;
        ans=0;
            int var=(s[x]==s[y])?2:0;
            ans=max(ans,var+go(x+1,y-1,s));
            ans=max(ans,go(x+1,y,s));
            ans=max(ans,go(x,y-1,s));
        return ans;
    }
public:
    int longestPalindromeSubseq(string s) {
        
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        int ans=go(0,n-1,s);
        return ans;
        
    }
};