#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
const ll mxlog=20;
ll n,m;
//m是好点对数量
vector<ll> g[N];
// pair<ll,ll> good[N];
pair<ll,ll> bad;
ll dep[N];
ll up[mxlog+5][N];
ll d[N];
ll dbad[N];
ll good[N];
void dfs(ll u,ll fa){
    dep[u]=dep[fa]+1;up[0][u]=fa;
    for(int i=1;i<=mxlog;i++) up[i][u]=up[i-1][up[i-1][u]];
    for(auto v:g[u]) if(v!=fa) dfs(v,u);
}
ll LCA(ll u,ll v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=mxlog;i>=0;i--) if(dep[up[i][u]]>=dep[v]) u=up[i][u];
    if(u==v) return u;
    for(int i=mxlog;i>=0;i--) if(up[i][u]!=up[i][v]) u=up[i][u],v=up[i][v];
    return up[0][u];
}
void getsum(ll u,ll fa){
    for(auto v:g[u]){
        if(v!=fa){
            getsum(v,u);
            d[u]+=d[v];
        }
    }
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
        ll u,v;
        cin>>u>>v;
        ll lca=LCA(u,v);
        d[u]++;d[v]++;
        d[lca]--;
        d[up[0][lca]]--;
        good[u]++;
        good[v]++;
    }
    getsum(1,0);
    cin>>bad.first>>bad.second;
    ll lca=LCA(bad.first,bad.second);
    ll cur=bad.first;
    while(cur!=up[0][lca]){
        dbad[cur]=1;
        cur=up[0][cur];
    }
    cur=bad.second;
    while(cur!=up[0][lca]){
        dbad[cur]=1;
        cur=up[0][cur];
    }
    ll cnt=0;
    for(int i=1;i<=n;i++) if(dbad[i]&&!d[i]&&!good[i]) cnt++;
    cout<<cnt;
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