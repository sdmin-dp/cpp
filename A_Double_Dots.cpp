#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m;
vector<ll> g[N];
bool vis[N];
ll dis[N];
void bfs(){
    queue<pair<ll,ll>> q;
    vis[1]=1;
    q.push({1,0});
    dis[1]=0;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        
        for(auto i:g[x.first]){
            if(dis[i]==-1) dis[i]=x.first;
            if(!vis[i]){
                q.push({i,x.second+1});
                vis[i]=1;
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=2;i<=n;i++) dis[i]=-1;
    bfs();
    for(int i=2;i<=n;i++){
        if(dis[i]==-1){
            cout<<"No"<<el;
            return;
        }
    }
    cout<<"Yes\n";
    for(int i=2;i<=n;i++){
        cout<<dis[i]<<el;
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