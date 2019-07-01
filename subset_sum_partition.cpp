//416. Partition Equal Subset Sum
//solved in o(n^2)
// subset sum partition 
class Solution {
    int n;
    int gs;
    int dp[205][20005];
    
int go(vector<int>& num,int idx,int total)
{
      if(idx==0)
      {
          int var1=total;
          int var2=gs-total;
          return abs(var2-var1);
      }
    int &ans=dp[idx][total];
    
    if(ans!=-1)
        return ans;
    
    ans=min(go(num,idx-1,total),go(num,idx-1,total+num[idx]));
            
    return ans;
    
}
    
public:
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            gs+=nums[i];
        }
        
        if(go(nums,n-1,0)==0)
            return true;
        return false;
    }
};