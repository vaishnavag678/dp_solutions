
//343. Integer Break
//O(N) solution
//recursive
class Solution {
   // int n;
    int dp[59][2];
    
    int go(int x,int var)
    {
        if(x<=0)
            return 1;
        
        int &ans=dp[x][var];
        
        if(ans!=-1)
            return ans;
        
        if(var==1)
        {
            for(int i=x-1;i>=1;i--)
            {
                ans=max(ans,i*go(x-i,0));
            }
        }
        else
        {
            for(int i=x;i>=1;i--)
            {
                ans=max(ans,i*go(x-i,0));
            }
        }
        return ans;
    }
    
public:
    int integerBreak(int n) {
    
       memset(dp,-1,sizeof(dp));
        return go(n,1);
    }
};

//*************************iterative 
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 0;
        dp[2] = 1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i] = max(dp[i],max(dp[j]*dp[i-j],max(j*dp[i-j],j*(i-j))));
            }
        }
        return dp[n];
    }
};