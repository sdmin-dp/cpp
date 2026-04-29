#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll fa[N];
ll dep[N],up[20][N];
void dfs(ll x,ll f){
    dep[x]=dep[f]+1;up[0][x]=f;
    for(int i=1;i<17;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(int i=1;i<n;i++) if(fa[i]==x) dfs(i,x);
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
    cin>>n;
    for(int i=1;i<n;i++) cin>>fa[i];
    fa[0]=-1;
    dfs(1,0);
    cin>>m;
    while(m--){
        ll len,x,lca;
        cin>>len;
        cin>>x;
        lca=x;
        for(int i=2;i<=len;i++){
            
        }
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
