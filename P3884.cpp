#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
vector<ll> g[N];
ll dep[N],up[20][N];
ll len[N];
ll mxdep=0;
void dfs(ll x,ll f){
    dep[x]=dep[f]+1;up[0][x]=f;
    len[dep[x]]++;
    mxdep=max(mxdep,dep[x]);
    for(int i=1;i<17;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(auto i:g[x]) if(i!=f) dfs(i,x);
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
    ll X,Y;
    cin>>n;
    for(int i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin>>X>>Y;
    dfs(1,0);
    cout<<mxdep<<el;
    for(int i=1;i<=n;i++) cerr<<dep[i]<<" ";
    ll kuan=0;
    for(int i=1;i<=n;i++) kuan=max(kuan,len[i]);
    cout<<kuan<<el;
    ll lca=LCA(X,Y);
    // cerr<<lca;
    cout<<abs(dep[lca]-dep[X])*2+abs(dep[lca]-dep[Y]);
}
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
