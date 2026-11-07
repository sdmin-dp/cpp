#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
bool vis[N];
ll ans[N];
void dfs(ll u,ll mx){
    if(ans[u]!=0){
        return;
    }
    ans[u]=mx;
    for(auto v:g[u]){
        if(!vis[v]){
            vis[v]=1;
            dfs(v,mx);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[v].push_back(u);
    }
    for(int i=n;i>=1;i--){
        if(ans[i]==0){
            dfs(i,i);
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}