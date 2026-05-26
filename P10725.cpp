#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll color[N];
vector<ll> g[N];
ll b,ans,dist;
ll pre[N];
void dfs(ll x,ll fa,ll dis){
    pre[x]=fa;
    if(dis>dist){
        b=x;
        dist=dis;
    }
    for(auto i:g[x]){
        if(i==fa) continue;
        dfs(i,x,dis+1);
    }
}
void dfs2(ll x,ll fa,ll dis){
    if(dis>dist&&color[x]!=color[b]){
        // b=x;
        dist=dis;
    }
    for(auto i:g[x]){
        if(i==fa) continue;
        dfs(i,x,dis+1);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>color[i];
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    dist=0;
    dfs2(b,0,0);
    cout<<dist;
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