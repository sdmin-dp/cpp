#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
const ll mod=1e9+7;
ll n;
bool f[N];
ll a[N];
ll dp[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        if(c=='0') f[i]=1;
        else f[i]=0;
        // cerr<<f[i]<<" ";
    }
    for(int i=1;i<n;i++){
        cin>>a[i];
        // cerr<<a[i]<<" ";
    }
    dp[n]=1;
    for(int i=n-1;i>=1;i--){
        if(!f[i]) continue;
        dp[i]=(dp[i+1]+dp[(i+a[i]<=n?i+a[i]:0)])%mod;
        // cerr<<i<<":"<<dp[i]<<" "<<dp[i+1]<<" "<<dp[(i+a[i]<=n?i+a[i]:0)]<<el;
    }
    cout<<dp[1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("passage.in","r",stdin);
    freopen("passage.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}