#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll dis[N];
ll mouse,cat;//猫窝和老鼠窝的位置
ll val[N];//每个奶酪的价值
void dijkstra(ll b,ll e){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;//堆优化
    q.push({0,b});
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    //dis[i]数组存的是b到i的最短路
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(x.first>dis[x.second]) continue;//一个小优化
        for(auto i:g[x.second]){
            if(dis[i.first]>x.second+i.second){//松弛
                dis[i.first]=x.second+i.second;
                q.push({i.first,dis[i.first]});
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    cin>>mouse>>cat;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
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