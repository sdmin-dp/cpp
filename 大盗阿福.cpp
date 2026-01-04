#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
ll dp[N];
void solve(){
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    memset(dp,0,sizeof(dp));
    dp[1]=a[1];
    dp[2]=max(a[1],a[2]);
    for(int i=3;i<=n;i++) dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    cout<<dp[n]<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}