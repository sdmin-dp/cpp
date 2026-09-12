#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n;
vector<ll> g[N];
ll dp[N][5];
void dfs(ll x,ll fa){
    ll sum[5]={0,0,0,0,0};
    for(auto i:g[x]){
        if(i==fa) continue;
        dfs(i,x);
        sum[2]+=dp[i][2];
        sum[3]+=dp[i][3];
        sum[4]+=dp[i][4];
    }
    dp[x][0]=1+sum[4];
    dp[x][3]=sum[2];
    dp[x][4]=sum[3];
    dp[x][1]=1e12;
    dp[x][2]=1e12;
    for(auto i:g[x]){
        if(i==fa) continue;
        dp[x][1]=min(dp[x][1],dp[i][0]+sum[3]-dp[i][3]);
        dp[x][2]=min(dp[x][2],dp[i][1]+sum[2]-dp[i][2]);
    }
    dp[x][1]=min(dp[x][0],dp[x][1]);
    dp[x][2]=min(dp[x][2],dp[x][1]);
    dp[x][3]=min(dp[x][2],dp[x][3]);
    dp[x][4]=min(dp[x][3],dp[x][4]);
    // dp[x][]=min(dp[x][0],dp[x][1]);
}
void solve(){
    cin>>n;
    for(int i=2;i<=n;i++){
        ll v;cin>>v;
        g[i].push_back(v);
        g[v].push_back(i);
    }
    dfs(1,0);
    cout<<dp[1][2];

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