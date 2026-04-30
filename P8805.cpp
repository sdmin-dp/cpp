#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll sum[N];
ll dep[N],up[22][N];
vector<ll> g[N];
void dfs(ll x,ll f){
    dep[x]=dep[f]+1;up[0][x]=f;
    for(int i=1;i<20;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(auto i:g[x]) if(i!=f) dfs(i,x);
}
ll LCA(ll u,ll v){
    if(dep[u]<dep[v]) swap(v,u);
    for(int i=20;i>=0;i--){
        if(dep[up[i][u]]>=dep[v]){
            u=up[i][u];
        }
    }
    if(u==v) return u;
    for(int k=20;k>=0;k--){
        if(up[k][u]!=up[k][v]){
            u=up[k][u];
            v=up[k][v];
        }
    }
    return up[0][u];
}
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        if(i!=fa){
            sum[i]=sum[x]+g[i].size();
            dfs(i,x);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    sum[1]=g[1].size();
    dfs(1,0);
    for(int i=1;i<=m;i++){
        
    }
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