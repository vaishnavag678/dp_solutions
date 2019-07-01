//complexity O(n^2)
//62. Unique Paths
//can be solved in O(n) space complexity
//recurence dp[x][y]=dp[x-1][y]+dp[x][y-1] for iteration 
class Solution {
    int dp[105][105];
    
    int go(int x,int y)
    {
        if(x<1||y<1)
            return 0;
        if(x==1&&y==1)
            return 1;
        int &ans=dp[x][y];
        if(ans!=-1)
            return ans;
        ans=go(x-1,y)+go(x,y-1);
        return ans;
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return go(m,n);
    }
};
//**********iterative in O(n) space 
class Solution {
 
public:
    int uniquePaths(int m, int n) {
       int dp[m+5]={1};
        for(int i=0;i<m;i++)
            dp[i]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
                dp[j]+=dp[j-1];
        }
     return dp[m-1];
    }
};