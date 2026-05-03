#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
bool vis[N];
ll match[N];
bool dfs(ll u){
    for(auto v:g[u]){
        if(!vis[v]){
            vis[v]=1;
            if(!match[v]||dfs(match[v])){
                match[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        // g[v].push_back(u);
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        if(dfs(i)) cnt++;
    }
    cout<<cnt;
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