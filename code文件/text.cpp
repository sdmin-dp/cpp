#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define el '\n'
const ll N=1e5+5;
const ll mxlog=20;
ll n;
vector<ll> g[N];
ll dep[N];
ll up[mxlog+5][N];
void dfs(ll x,ll fa){
    dep[x]=dep[fa]+1;up[0][x]=fa;
    for(int i=1;i<=mxlog;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(auto i:g[x]) if(i!=fa) dfs(i,x);
}
ll LCA(ll u,ll v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=mxlog;i>=0;i--) if(dep[up[i][u]]>=dep[v]) u=up[i][u];
    if(u==v) return u;
    for(int i=mxlog;i>=0;i--) if(dep[up[i][u]]!=dep[up[i][v]]) u=up[i][u],v=up[i][v];
    return up[0][u];
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<LCA(5,3);
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