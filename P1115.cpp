#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
ll n;
ll a[N];
ll dp[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        if(dp[i-1]+a[i]<=0) dp[i]=0; 
        else dp[i]=dp[i-1]+a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    // cout<<dp[n];
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}