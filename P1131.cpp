#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
ll n,root;
vector<pair<ll,ll>> g[N];
ll dp[N];
ll ans=0;
void dfs(ll u,ll fa){
    for(auto [v,w]:g[u]){
        if(v==fa) continue;
        dfs(v,u);
        dp[u]=max(dp[u],dp[v]+w);
    }
    for(auto [v,w]:g[u]){
        if(v==fa) continue;
        ans+=dp[u]-(dp[v]+w);
    }

}
void solve(){
    cin>>n>>root;
    for(int i=1;i<n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(root,0);
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