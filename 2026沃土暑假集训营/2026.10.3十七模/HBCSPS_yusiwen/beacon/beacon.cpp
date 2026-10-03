#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,s,t,k;
ll lig[N];
vector<pair<ll,ll>> g[N];
ll dijkstra(ll s,ll t){
    vector<ll> dis(n+1,inf);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        ll u=q.top().second,w=q.top().first;q.pop();
        if(w>dis[u]) continue;
        for(auto i:g[u]){
            ll v=i.first;
            if(dis[v]>w+i.second){
                dis[v]=w+i.second;
                q.push({dis[v],v});
            }
        }
    }
    return dis[t];
}
ll dijkstra2(ll s,ll t,ll mndis){
    vector<ll> dis(n+1,inf);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    dis[s]=0;
    q.push({0,s});
    ll ans=0;
    while(!q.empty()){
        ll u=q.top().second,w=q.top().first;q.pop();
        if(w>dis[u]) continue;
        for(auto i:g[u]){
            ll v=i.first;
            if(w+i.second==mndis){
                ans++;
            }
            if(dis[v]>w+i.second){
                dis[v]=w+i.second;
                q.push({dis[v],v});
                
            }
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m>>s>>t>>k;
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(ll i=1;i<=k;i++){
        cin>>lig[i];
    }
    ll stdis=dijkstra(s,t);
    ll ans=0;
    for(int i=1;i<=k;i++){
        ll x=lig[i];
        ll sxdis=dijkstra(s,x),txdis=dijkstra(t,x);
        if(sxdis+txdis!=stdis) continue;
        ll sxnum=dijkstra2(s,x,sxdis),txnum=dijkstra2(t,x,txdis);
        ans+=sxnum*txnum;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("beacon.in","r",stdin);
    freopen("beacon.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}