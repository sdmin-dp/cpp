#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,ans,mouse,cat;//猫窝和老鼠窝的位置
vector<pair<ll,ll>> g[N];
ll dis[N],val[N];//每个奶酪的价值
void dijkstra(ll b){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;//堆优化
    q.push({0,b});
    memset(dis,0x3f,sizeof(dis));
    dis[b]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(x.first>dis[x.second]) continue;
        for(auto i:g[x.second]){
            if(dis[i.first]>dis[x.second]+i.second){
                dis[i.first]=x.first+i.second;
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
    dijkstra(mouse);
    for(int i=1;i<=n;i++) cerr<<dis[i]<<" ";
    for(int i=1;i<=n;i++) if(dis[i]<dis[cat]) ans+=val[i];
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