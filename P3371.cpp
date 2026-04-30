#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll b;
ll dis[N];
vector<pair<ll,ll>> g[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
void dijkstra(){
    q.push({0,b});
    for(int i=1;i<=n;i++) dis[i]=(1<<31)-1;
    dis[b]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        swap(x.first,x.second);
        if(x.second>dis[x.first]) continue;
        for(auto i:g[x.first]){
            if(dis[x.first]+i.second>dis[i.first]){
                dis[i.first]=dis[x.first]+i.second;
                q.push({dis[i.first],i.first});
            }
        }
    }
}
void solve(){
    cin>>n>>m>>b;
    for(int i=1;i<=m;i++){
        ll u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    dijkstra();
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
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