class Solution {
    
    int vis[1005];
    int dp[1005];
    int n;
    //basic problem implement carefully 
    int go(int idx,vector<int>& days, vector<int>& costs)
    {
        if(idx>=n)
            return 0;
        
        int &ans=dp[idx];
        
        if(ans!=-1)
            return dp[idx];
        
        if(vis[idx]==0)
            return ans=go(idx+1,days,costs);
        
        int var1=costs[0]+go(idx+1,days,costs);
        
        int var2=costs[1]+go(idx+7,days,costs);
        
        int var3=costs[2]+go(idx+30,days,costs);
        
        return ans=min(var1,min(var2,var3));
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days[days.size()-1]+1;
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<days.size();i++)
            vis[days[i]]=1;
        return go(0,days,costs);
    }
};