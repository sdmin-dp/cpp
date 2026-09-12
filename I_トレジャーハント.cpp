#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll inf=0x7f7f7f7f7f7f7f7f;
ll n,m,t;
ll a[N];
vector<pair<ll,ll>> g[N],g2[N];
ll dis[N],dis2[N];
void dijkstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,1});
    memset(dis,0x7f,sizeof(dis));
    dis[1]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(x.first>dis[x.second]) continue;
        for(auto i:g[x.second]){
            if(dis[i.first]>x.first+i.second){
                dis[i.first]=x.first+i.second;
                q.push({dis[i.first],i.first});
            }
        }
    }
}
void dijkstra2(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,1});
    memset(dis2,0x7f,sizeof(dis2));
    dis2[1]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(x.first>dis2[x.second]) continue;
        for(auto i:g2[x.second]){
            if(dis2[i.first]>x.first+i.second){
                dis2[i.first]=x.first+i.second;
                q.push({dis2[i.first],i.first});
            }
        }
    }
}
void solve(){
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        ll u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g2[v].push_back({u,w});
    }
    dijkstra();
    dijkstra2();
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(dis[i]>=inf||dis2[i]>=inf) continue;
        ans=max(ans,(t-dis[i]-dis2[i])*a[i]);
    }
    cout<<ans<<el;
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