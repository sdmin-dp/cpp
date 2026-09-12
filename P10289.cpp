#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=2e5+5;
ll n,k,m;
ll dep[N],up[22][N];
bool dor[N];
vector<ll> g[N];
queue<array<ll,3>> q;
ll dis[N];
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
void bfs(){
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto i:g[x[0]]){
            if(dis[i]!=inf) continue;
            if(i==x[1]) continue;
            q.push({i,x[0],x[2]+1});
            dis[i]=x[2]+1;
        }
    }
}
void solve(){
    cin>>n>>k>>m;
    // cerr<<n<<" "<<k<<" "<<m;
    for(int i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    // for(int i=1;i<=n;i++) dis[i]=inf;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=k;i++){
        ll u;cin>>u;
        dor[u]=1;
        dis[u]=0;
        q.push({u,0,0});
    }
    bfs();
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        ll lca=LCA(u,v);
        ll len1=abs(dep[lca]-dep[u])+abs(dep[lca]-dep[v]);
        ll len2=dis[u]+dis[v];
        // cerr<<len1<<" "<<len2<<el;
        cout<<min(len1,len2)<<el;
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