#include<bits/stdc++.h>
#define ll int
using namespace std;
#define el '\n'
const ll N=5e5+5;
ll n,q;
ll dep[N],up[22][N];
vector<ll> g[N];
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
    cin>>n>>q;
    for(int i=1;i<n;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=q;i++){
        ll a,b,c,d,lca1,lca2;
        cin>>a>>b>>c>>d;
        lca1=LCA(a,b);lca2=LCA(c,d);
        ll flag=0;
        if(dep[lca1]>=dep[lca2]){
            if(lca1==LCA(lca1,c)||lca1==LCA(lca1,d)) flag=1;
        }else{
            swap(a,c);swap(b,d);swap(lca1,lca2);
            if(lca1==LCA(lca1,c)||lca1==LCA(lca1,d)) flag=1;
        }
        cout<<(flag?'Y':'N')<<el;
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
