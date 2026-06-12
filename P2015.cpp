#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,q;
ll a[N];
vector<pair<ll,ll>> g[N];
ll dp[N][N];
ll len[N];
void dfs(ll u,ll fa){
    len[u]=1;
    dp[u][1]=a[u];
    for(auto [v,w]:g[u]){
        if(v==fa) continue;
        a[v]=w;
        dfs(v,u);
        ll maxj=min(q+1,len[u]+len[v]);
        for(ll j=maxj;j>=1;j--){
            ll maxk=min(j-1,len[v]);
            ll mink=max(0ll,j-len[u]);
            for(int k=mink;k<=maxk;k++){
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
            }
        }
        len[u]+=len[v];
    }
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    cout<<dp[1][q+1];
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