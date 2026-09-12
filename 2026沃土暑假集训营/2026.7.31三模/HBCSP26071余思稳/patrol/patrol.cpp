#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e3+5;
ll n,m;
vector<ll> g[N];
ll dep[N],up[22][N];
ll d[N];
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
void dfs2(ll x,ll fa){
    // if(g[x].size()==1) return;
    for(auto i:g[x]){
        if(i!=fa){
            dfs2(i,x);
            d[x]+=d[i];
        }
    }
    // cerr<<x<<":"<<d[x]<<el;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        ll lca=LCA(u,v);
        
        d[u]++;d[v]++;
        d[lca]--;d[up[0][lca]]--;
        // for(int i=1;i<=n;i++) cerr<<d[i]<<" ";
        // cerr<<el; 
    }
    dfs2(1,0);
    // for(int i=1;i<=n;i++) cerr<<d[i]<<" ";
    ll mx=-1;
    for(int i=1;i<=n;i++) mx=max(mx,d[i]);
    ll cnt=0;
    for(int i=1;i<=n;i++) if(d[i]==mx) cnt++;
    cout<<mx<<el<<cnt<<el;
    for(int i=1;i<=n;i++) if(d[i]==mx) cout<<i<<" ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("patrol.in","r",stdin);
    freopen("patrol.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}