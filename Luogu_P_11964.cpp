#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e2+5;
ll n,m,k;
ll dis[25];
bool vis[N][25];
vector<ll> g[N];
void dfs(ll x,ll step){
    dis[step]++;
    if(step==k) return;
    for(auto i:g[x]){
        if(!vis[i][step+1]){
            vis[i][step+1]=1;
            dfs(i,step+1);
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        dfs(i,0);
        for(int i=1;i<=k;i++){
            cout<<dis[i]<<" ";
        }
        cout<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}