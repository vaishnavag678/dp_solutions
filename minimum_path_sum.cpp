class Solution {
    
    long long dp[1005][1005];
    int n,m;
    
    long long  go(int x,int y,vector<vector<int>>& grid)
    {
        if(x>=n||y>=m)
            return INT_MAX;
        if(x==n-1&&y==m-1)
            return grid[x][y];
       // if()
        long long &ans=dp[x][y];
        if(ans!=-1)
            return dp[x][y];
        ans=INT_MAX;
        long long val=grid[x][y];
        ans=min(ans,val+go(x+1,y,grid));
        ans=min(ans,val+go(x,y+1,grid));
        
        return ans;
            
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
        n=grid.size();
        m=grid[0].size();
        
        return go(0,0,grid);
        
    }
};