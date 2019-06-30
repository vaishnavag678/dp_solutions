#include<bits/stdc++.h>
#define ll      long long int
#define pb      push_back
#define pp      pop_back
#define mp      make_pair
#define all(a)  (a).begin(),(a).end()
#define mod     1000000007
#define fast     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
         /////////////************vessi******************/////////////////


class Solution {
    int dp[1005][1005];
    int go(int i,int j,string &s)
    {
        if(i>=j)
            return 1;
        int &ans=dp[i][j];
        if(ans!=-1)
            return ans;
        
        if(s[i]!=s[j])
            return ans=0;
        return ans=go(i+1,j-1,s);
    }
public:
    string longestPalindrome(string s) 
    {
        
        int n=s.size();
        int ans=0;
        int x=0;
        int y=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(go(i,j,s)){
                   if(ans<j-i+1)
                   {
                       ans=j-i+1;
                       x=i;
                       y=j;
                   }
                }
            }
        }
        string xx="";
        for(int i=x;i<=y;i++)
        {
            xx+=s[i];
        }
    return xx;      
    }
};