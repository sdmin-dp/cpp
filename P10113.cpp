#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll dep[N],up[25][N];
ll fa[N];
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
void solve(){
    cin>>n;
    fa[0]=-1;
    for(int i=1;i<n;i++){
        ll x;
        cin>>x;
        fa[i]=x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(0,-1);
    cin>>m;
    for(int i=1;i<=m;i++){
        ll len,x,lca;
        cin>>len>>lca;
        for(int j=2;j<=len;j++){
            cin>>x;
            lca=LCA(lca,x);
        }
        ll cur=lca;
        ll ans=lca;
        while(cur!=-1){
            ans=max(ans,cur);
            cur=fa[cur];
        }
        cout<<ans<<el;
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