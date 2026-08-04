#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
ll n;
map<ll,vector<ll>> g;
map<ll,bool> vis;
ll ans=1;
void dfs(ll x){
    ans=max(ans,x);
    for(auto i:g[x]){
        if(!vis[i]){
            vis[i]=1;
            dfs(i);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1]=1;
    dfs(1);
    cout<<ans;
    // cerr<<20*20*20*20*20*20;
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
