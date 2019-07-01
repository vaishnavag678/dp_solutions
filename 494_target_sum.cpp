//complexity O(n^2)
//494. Target Sum
class Solution 
{
    int n;
    int dp[25][2005];
    
    int temp;
    int go(int idx,int s,vector<int>& num)
    {
        if(idx==n)
        {
            if(s==temp)
                return 1;
            return 0;
        }
        if(dp[idx][1000+s]!=-1)
            return dp[idx][1000+s];
        
       int add=go(idx+1,s-num[idx],num);
        int subtract=go(idx+1,s+num[idx],num);
        
        return dp[idx][1000+s]=add+subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        temp=S;
       return go(0,0,nums);
    }
};