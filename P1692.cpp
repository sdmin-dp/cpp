#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n,m;
vector<ll> g[N];
vector<bool> ans,vis;
ll mx;
bool check(ll x){
    for(auto i:g[x]) if(vis[i]) return 0;
    return 1;
}
void dfs(ll x,ll sum){
    if(sum+(n-x+1)<=mx) return;
    if(x==n+1){
        if(sum>mx) ans=vis,mx=sum;
        return;
    }
    if(check(x)){
        vis[x]=1;
        dfs(x+1,sum+1);
        vis[x]=0;
    }
    dfs(x+1,sum);
}
void solve(){
    cin>>n>>m;
    ans.resize(n+1);
    vis.resize(n+1);
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<mx<<el;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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