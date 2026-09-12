#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+5;
const ll M=1e2+5;
ll n,m;
ll a[M],b[N];
ll dp[N];
ll k=0;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        k=max(k,a[i]);
    }
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        ll mx=-1e18;
        for(int j=1;j<=m;j++){
            if(i-a[j]<=0) continue;
            mx=max(mx,dp[i-a[j]]);
        }
        if(mx==-1e18) mx=0;
        dp[i]=mx+b[i];
    }
    ll ans=-1e18;
    for(int i=0;i<k;i++) ans=max(ans,dp[n-i]);
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}