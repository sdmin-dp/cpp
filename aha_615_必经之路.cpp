#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,q,idx,cnt;
vector<ll> g[N],ng[N];
ll dfn[N],low[N],color[N],dep[N],f[N][21];
vector<pair<ll,ll>> bridge;
map<pair<ll,ll>,bool> mp;
void dfs_tarjan(ll x,ll fa){
    dfn[x]=low[x]=++idx;
    for(auto i:g[x]){
        if(i==fa) continue;
        if(!dfn[i]){
            dfs_tarjan(i,x);
            low[x]=min(low[x],low[i]);
            pair<ll,ll> p={x,i};
            if(low[i]>dfn[x]) bridge.push_back(p);
        }else low[x]=min(low[x],dfn[i]);
    }
}
void dfs_color(ll x,ll c){
    color[x]=c;
    for(auto i:g[x]){
        pair<ll,ll> p={min(x,i),max(x,i)};
        if(color[i]||mp[p]) continue;
        dfs_color(i,c);
    }
}
void dfs_lca(ll x,ll fa,ll d){
    dep[x]=d;
    f[x][0]=fa;
    for(int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
    for(auto i:ng[x]) if(i!=fa) dfs_lca(i,x,d+1);
}
ll get_lca(ll x,ll y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
void solve(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
        ll x,y;
        scanf("%lld%lld",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    idx=0;
    dfs_tarjan(1,0);
    for(auto &i:bridge){
        if(i.first>i.second) swap(i.first,i.second);
        mp[i]=1;
    }
    cnt=0;
    for(int i=1;i<=n;i++) if(!color[i]) dfs_color(i,++cnt);
    for(auto &i:bridge){
        ll u=color[i.first],v=color[i.second];
        ng[u].push_back(v);
        ng[v].push_back(u);
    }
    dfs_lca(1,0,1);
    cin>>q;
    while(q--){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        ll u=color[a],v=color[b];
        ll lca=get_lca(u,v);
        printf("%lld\n",dep[u]+dep[v]-2*dep[lca]);
    }
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}
