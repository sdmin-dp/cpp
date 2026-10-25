#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,m;
ll w[105],v[105];
ll dp[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=w[i];j<=m+5000;j++){
            dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    ll ans=1e16;
    for(int i=m;i<=m+5000;i++){
        ans=min(ans,dp[i]);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}