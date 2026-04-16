#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
const ll M=1e3+5;
ll n,m,k;
ll dp[M],dp2[M];
pair<ll,ll> a[N];//pair<价值,高度>
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=1;i<=n;i++){
        for(int j=a[i].second;j<=m;j++){
            dp[j]=max(dp[j],dp[j-(ll)(a[i].second*0.8)]+a[i].first);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=a[i].second;j<=m;j++){
            dp2[j]=max(dp2[j],dp2[j-a[i].second]+a[i].first);
        }
    }
    // for(int i=0;i<=m;i++) cerr<<dp[i]<<" ";
    // cerr<<el;
    // for(int i=0;i<=m;i++) cerr<<dp2[i]<<" ";
    ll ans=dp2[m];
    for(int i=1;i<=n;i++){
        if(a[i].second<k) continue;
        ans=max(ans,dp[m-a[i].second]+a[i].first);
        cerr<<i<<" "<<dp[m-a[i].second]+a[i].first<<" "<<m-a[i].second<<" "<<ans<<" "<<dp[28]<<el;
    }
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