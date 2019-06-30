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

ll a[1000005];
ll dp[1000005];
ll n;
ll lis(ll idx)
{
    if(idx>=n)
        return 0;
    ll &ret=dp[idx];

    if(ret!=-1)
        return ret;
    ret=1;            //bhai ye us particular character ke liye
    for(ll i=idx+1;i<n;i++)
    {
        if(a[i]>a[idx])
            ret=max(ret,1+lis(i));
    }
    return ret;
}


int main()
{
    //cout<<"enter the number of elements in the array"<<"\n";
    ll t;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(ll i=0;i<n;i++)
                cin>>a[i];

        ll ans=0;
        //without these loop you are incomplete dude :)
        for(ll i=0;i<n;i++)
            ans=max(ans,lis(i)); 
            cout<<ans<<"\n";
    }

}
