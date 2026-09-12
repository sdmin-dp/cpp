#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m;
vector<ll> g[N];
vector<pair<ll,ll>> ans;
bool vis[N];
void dfs(ll x){
    for(auto i:g[x]){
        if(!vis[i]){
            vis[i]=1;
            ans.push_back({x,i});
            dfs(i);
        }
    }
}
void bfs(){
    queue<ll> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        auto x=q.front();q.pop();
        for(auto i:g[x]){
            if(!vis[i]){
                vis[i]=1;
                ans.push_back({x,i});
                q.push(i);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1]=1;
    dfs(1);
    memset(vis,0,sizeof(vis));
    bfs();
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<el;
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