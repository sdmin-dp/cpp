#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
vector<pair<ll,ll>> g[N];
ll pre[N];
ll dis[N];
void dijkstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,1});
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(x.first>dis[x.second]) continue;
        for(auto i:g[x.second]){
            if(dis[i.first]>x.first+i.second){
                dis[i.first]=x.first+i.second;
                pre[i.first]=x.second;
                q.push({dis[i.first],i.first});
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra();
    if(dis[n]>=inf){
        cout<<-1;
        return;
    }
    ll cur=n;
    vector<ll> v;
    while(cur!=1){
        v.push_back(cur);
        cur=pre[cur];
    }
    v.push_back(1);
    reverse(v.begin(),v.end());
    for(auto i:v) cout<<i<<" ";
}
int main() {
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
