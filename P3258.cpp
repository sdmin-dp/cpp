#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=3e5+5;
ll n;
vector<ll> g[N];
ll d[N];
ll dep[N],up[22][N];
ll a[N];
void dfs(ll x,ll f){
    dep[x]=dep[f]+1;up[0][x]=f;
    for(int i=1;i<20;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(auto i:g[x]) if(i!=f) dfs(i,x);
}
void dfs2(ll x,ll fa){
    for(auto i:g[x]){
        if(i!=fa){
            dfs2(i,x);
            d[x]+=d[i];
        }
    } 
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
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for(int i=2;i<=n;i++){
        ll l=a[i-1],r=a[i],lca;
        // cin>>l>>r;
        lca=LCA(l,r);
        d[lca]--;
        d[up[0][lca]]--;
        d[l]++;
        d[up[0][r]]++;
    }
    dfs2(1,0);
    cout<<d[1]<<el;
    for(int i=2;i<=n;i++) cout<<d[i]<<el;
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