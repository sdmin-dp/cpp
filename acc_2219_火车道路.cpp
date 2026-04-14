#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5;
const ll M=4e5;
vector<vector<ll>>e(N+2);
ll pos[N+2],a[M+2];
ll d[N+2];
ll lca[22][N+2];
void dfs(ll u,ll f){
    lca[0][u]=f;
    for(ll i=1;i<=20;i++){
        lca[i][u]=lca[i-1][lca[i-1][u]];
    }
    for(auto v:e[u]){
        if(v==f) continue;
        d[v]=d[u]+1;
        dfs(v,u);
        pos[u]=min(pos[u],pos[v]);
    }
}
ll LCA(ll u,ll  v){
    if(d[u]<d[v]){
        swap(u,v);
    }
    for(ll i=20;i>=0;i--){
        if(d[lca[i][u]]>=d[v]){
            u=lca[i][u];
        }
    }
    if(u==v){
        return u;
    }

    for(ll i=20;i>=0;i--){
        if(lca[i][u]!=lca[i][v]){
            u=lca[i][u];
            v=lca[i][v];
        }
    }

    return lca[0][u];
}
ll dis(ll u,ll v){
    return d[u]+d[v]-2*d[LCA(u,v)];
}
void solve(){
    ll n,m,r;
    cin>>n>>m>>r;
    for(ll i=1;i<n;i++){
        pos[i]=m+2;
        ll u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    pos[n]=m+2;
    for(ll i=1;i<=m;i++){
        cin>>a[i];
        pos[a[i]]=min(pos[a[i]],i);
    }

    dfs(r,0);

    ll last=r;
    ll ans=0;
    for(ll i=1;i<=m;i++){
        if(pos[a[i]]==i){
            ans+=dis(last,a[i]);
            last=a[i];
        }
    }
    cout<<ans<<'\n';
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    
    return 0;
}
