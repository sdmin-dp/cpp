#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e5+5;
const ll mxlog=20;
ll n,m,b;
vector<ll> g[N];
ll up[mxlog+5][N],dep[N];
bool vis[N];
void dfs(ll x,ll fa){
    dep[x]=dep[fa]+1;
    up[0][x]=fa;
    for(int i=1;i<=mxlog;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(auto i:g[x]) if(i!=fa) dfs(i,x);
}
void dfs2(ll x,ll lca){
    vis[x]=1;
    if(x==lca) return;
    dfs2(up[0][x],lca);
}
ll LCA(ll u,ll v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=mxlog;i>=0;i--){
        if(dep[up[i][u]]>=dep[v]){
            u=up[i][u];
        }
    }
    if(u==v) return u;
    for(int i=mxlog;i>=0;i--){
        if(up[i][u]!=up[i][v]){
            u=up[i][u];
            v=up[i][v];
        }
    }
    return up[0][u];
}
void solve(){
    cin>>n>>m>>b;
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    ll last=b,ans=0;
    ll lastlca=0;
    for(int i=1;i<=m;i++){
        ll x;
        cin>>x;
        if(vis[x]) continue;
        ll fa=LCA(last,x);
        ll t=llabs(dep[fa]-dep[x])+llabs(dep[fa]-dep[last]);
        if(lastlca==0){
            dfs2(x,fa);
            dfs2(last,fa);
        }
        // else if(dep[fa]>dep[lastlca]){
        //     dfs2(lastlca,fa);
        //     dfs2(x,fa);
        // }else{
        //     dfs2(fa,lastlca);
        // }
        cout<<fa<<" "<<dep[fa]<<el;
        ans+=t;
        last=x;
        lastlca=fa;
    }
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