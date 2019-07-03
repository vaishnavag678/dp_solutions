//minimum coin change problem 
//and printing the combination as well

//minimum coin change problem 
//and printing the combination as well


#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main()
{

    ll value,n;//n==number of coins
	//cin>>value;
	ll i,j;
	cin>>n;
//	ll dp[n+5][value+5];
	ll coin[n+5];

	for(i=0;i<n;i++)
		cin>>coin[i];
		
		cin>>value;
		
		ll dp[n+5][value+5];
	sort(coin,coin+n);

    for(i=0;i<=value;i++)
    {
        if(i%coin[0]==0)
            dp[0][i]=i/coin[0];
        else
            dp[0][i]=1e18;
    }
	for( i=1;i<n;i++)
	{
		for(j=0;j<=value;j++)
		{
		    if(j==0)
			dp[i][j]=0;
		     else if(i>=1&&j>=coin[i])
				dp[i][j]=min(dp[i-1][j],1+dp[i][j-coin[i]]);
			else if(i>=1&&j<coin[i])
				dp[i][j]=dp[i-1][j];

		}
	}
	
	for(i=0;i<n;i++)
	{    for(j=0;j<=value;j++)
	        cout<<dp[i][j]<<" ";
	   cout<<"\n";
	}
	if(dp[n-1][value]==1e18)
	{
		cout<<"not possible to make the number"<<"\n";
	}
	cout<<"minimum coins required to make "<<value<<" is "<<dp[n-1][value]<<"\n";
	
	i=n-1;
	j=value;

	while(j>0&&i>=0)
	{
		if(dp[i-1][j]==dp[i][j])
			i--;
		else 
		{
			cout<<"the coin used is "<<coin[i]<<"\n";
			j=j-coin[i];
		}
	}

}