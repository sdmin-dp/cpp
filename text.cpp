#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m,k,idx,dfn[N],low[N],sz[N],ans;
vector<ll> g[N];
void tarjan(ll u,ll fa){
    dfn[u]=low[u]=++idx;
    sz[u]=1;
    for(auto v:g[u]){
        if(v==fa)continue;
        if(!dfn[v]){
            tarjan(v,u);
            sz[u]+=sz[v];
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u])ans=max(ans,sz[v]);
        }else low[u]=min(low[u],dfn[v]);
    }
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);g[v].push_back(u);
    }
    tarjan(k,0);
    cout<<ans<<el;
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
