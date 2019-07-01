//complexity   O(N^2)
//classic dp
//72. Edit Distance

// totally brute force solution 

/********for itertive base case

    if(j==0)
    dp[i][j]=i;
    if(i==0)
    dp[i][j]=j;

    instead simple reccurnece


*****************/

class Solution {
    int dp[1005][1005];
    
    int go(string &word1,string &word2,int n,int m)
    {
        if(n==0)
            return m;
        if(m==0)
            return n;
        int &ans=dp[n][m];
        
        if(ans!=-1)
            return ans;
        
        if(word1[n-1]==word2[m-1])
         return  ans=go(word1,word2,n-1,m-1);
        
        int var1=1+go(word1,word2,n-1,m);//delete
        int var2=1+go(word1,word2,n,m-1);//add
        int var3=1+go(word1,word2,n-1,m-1);//replace
        
        return ans=min(var1,min(var2,var3));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        memset(dp,-1,sizeof(dp));
        
        return go(word1,word2,n,m);
    }
};