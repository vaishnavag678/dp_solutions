
#include<bits/stdc++.h>
using namespace std;
long long mod =1000000007;

long long dp[2][1000005]={0};

int a[3];

long long calc(int a[],int m,int n)
{
    if(n==0)
        return 1;
       if(n<0)
        return 0;   
    if(m<=0&&n>0)
        return 0;
    
   //cout<<"vessi"<<"  "<<n<<" "<<m<<"\n";
    
    if(dp[m-1][n]!=-1){
      //cout<<"vessi"<<"  "<<n<<" "<<m<<" "<<dp[m][n]<<"\n";
        return dp[m][n];
      }

     //cout<<"vessi"<<"  "<<n<<" "<<m<<"\n";  

    dp[m][n]=calc(a,m-1,n)+calc(a,m,n-a[m-1]);

    return dp[m][n];
}

long long countWays(int m)
{
   for(int i=0;i<2;i++)
    for(int j=0;j<1000005;j++)
          dp[i][j]=-1;

  
   a[0]=1;
   a[1]=2;

    long long ans=calc(a,2,m);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin>>m;
        cout<<countWays(m)<<"\n"; 
    }
    return 0;
}




