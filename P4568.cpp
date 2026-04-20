#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,k;
vector<pair<ll,ll>> g[N];
ll dis[N][20];
ll b,e;
void dijkstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,b});
    memset(dis,0x3f,sizeof(dis));
    for(ll i=1;i<=k;i++) dis[1][0]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        for(int i=1;i<=k;i++){
            if(dis[])
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra();
    
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
