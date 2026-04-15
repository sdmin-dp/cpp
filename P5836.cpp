#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll dep[N],up[15][N];
char a[N];
vector<ll> g[N];
pair<ll,ll> cnt[N];//pair<H,G>
void dfs(ll x,ll f){
    dep[x]=dep[f]+1;up[0][x]=f;
    for(int i=1;i<10;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(auto i:g[x]) if(i!=f) dfs(i,x);
}
ll LCA(ll u,ll v){
    if(dep[u]<dep[v]) swap(v,u);
    for(int i=9;i>=0;i--){
        if(dep[up[i][u]]>=dep[v]){
            u=up[i][u];
        }
    }
    if(u==v) return u;
    for(int k=9;k>=0;k--){
        if(up[k][u]!=up[k][v]){
            u=up[k][u];
            v=up[k][v];
        }
    }
    return up[0][u];
}
void dfs2(ll x,ll fa){
    a[x]=a[fa];
    if(a[x]=='H') cnt[x].first++;
    else cnt[x].second++;
    for(auto i:g[x]) if(i!=fa) dfs2(i,x);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    dfs2(1,0);
    for(int i=1;i<=m;i++){
        ll b,e;
        char c;
        cin>>b>>e>>c;
        
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
