#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll inf=1e12;
const ll mod=1e9+7;
ll n,m;
pair<ll,ll> a[N];
array<ll,3> dp[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=1;i<=m;i++) dp[i]={-1,inf,0};
    dp[0]={0,0,1};
    //价值，数量，方案数
    for(int i=1;i<=n;i++){
        for(int j=a[i].first;j<=m;j++){
            if(dp[j-a[i].first][0]==-1) continue;
            array<ll,3> x={dp[j-a[i].first][0]+a[i].second,dp[j-a[i].first][1]+1,dp[j-a[i].first][2]};
            if(x[0]>dp[j][0]) dp[j]=x;
            else if(x[0]==dp[j][0]&&x[1]<dp[j][1]) dp[j]=x;
            else if(x[0]==dp[j][0]&&x[1]==dp[j][1]) dp[j][2]=(dp[j][2]+x[2])%mod;
        }
    }
    array<ll,3> ans={0,inf,0};
    for(int j=1;j<=m;j++){
        if(ans[0]<dp[j][0]) ans=dp[j];
        else if(ans[0]==dp[j][0]&&ans[1]>dp[j][1]) ans=dp[j];
        else if(ans[0]==dp[j][0]&&ans[1]==dp[j][1]) ans[2]=(dp[j][2]+ans[2])%mod;
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("module.in","r",stdin);
    freopen("module.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}