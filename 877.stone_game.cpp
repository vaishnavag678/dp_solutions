//again an interval dp
//solved in O(n^2) complexity
//877.stone game leetcode
//top down approach 

class Solution {
    int n;
    int dp[1005][1005][2];
    int go(int l,int r,int idx,vector<int>& piles)
    {
        if(l>r)
            return 0;
        int &ans=dp[l][r][idx];
        if(ans!=-1)
            return ans;
        ans=max(ans,go(l+1,r,idx^1,piles));
        ans=max(ans,go(l,r-1,idx^1,piles));
        
        return ans;
    }
public:
    bool stoneGame(vector<int>& piles) {
        
        memset(dp,-1,sizeof(dp));
        n=piles.size();
        
        go(0,n-1,0,piles);//third parameter denotes alex and box
        
        if(dp[0][n-1][0]>dp[0][n-1][1])
            return true;
        return false;
        
    }
};