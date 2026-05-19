#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
ll ans=0;
vector<array<ll,3>> g[N];
ll dep[N],up[22][N];
ll cnt[N];
void dfs(ll x,ll f){
    dep[x]=dep[f]+1;up[0][x]=f;
    for(int i=1;i<20;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(auto i:g[x]) if(i[0]!=f) dfs(i[0],x);
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
ll dfs2(ll x,ll fa){
    for(auto i:g[x]){
        if(i[0]!=fa){
            cnt[x]+=dfs2(i[0],x);
            ans+=min(i[2],cnt[i[0]]*i[1]);
        }
    }
    return cnt[x];
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll u,v,w1,w2;
        cin>>u>>v>>w1>>w2;
        g[u].push_back({v,w1,w2});
        g[v].push_back({u,w1,w2});
    }
    dfs(1,0);
    for(int i=2;i<=n;i++){
        ll lca=LCA(i,i-1);
        cnt[i]++;cnt[i-1]++;cnt[lca]-=2;
    }
    // for(int i=1;i<=n;i++){
    //     for(auto j:g[i]){
    //         if(j[0]!=up[0][i]){
    //             cnt[i]+=cnt[j[0]];
    //         }
    //     }
    //     cerr<<cnt[i]<<" ";
    // }
    dfs2(1,0);
    // for(int i=1;i<=n;i++){
    //     for(auto j:g[i]){
    //         if(j[0]!=up[0][i]){
    //             ans+=min(j[2],cnt[j[0]]*j[1]);
    //         }
    //     }
    // }
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