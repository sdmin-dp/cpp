#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e4+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll dep[N],up[20][N];
void dfs(ll x,ll f){
    dep[x]=dep[f]+1;up[0][x]=f;
    for(int i=1;i<17;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(auto i:g[x]) if(i.first!=f) dfs(i.first,x);
}
ll LCA(ll u,ll v){
    if(dep[u]<dep[v]) swap(v,u);
    for(int i=17;i>=0;i--){
        if(dep[up[i][u]]>=dep[v]){
            u=up[i][u];
        }
    }
    if(u==v) return u;
    for(int k=17;k>=0;k--){
        if(up[k][u]!=up[k][v]){
            u=up[k][u];
            v=up[k][v];
        }
    }
    return up[0][u];
}
void solve(){
    cin>>n;
    for(int i=2;i<=n;i++){
        ll x,y,z;cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    dfs(1,0);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<el;
    }
}
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
