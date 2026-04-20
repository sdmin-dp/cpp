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
        for(auto i:g[x.second]){
            for(int j=0;j<=k;j++){
                if(dis[i.first][j]>dis[x.second][j]+i.second){
                    dis[i.first][j]=dis[x.second][j]+i.second;
                    q.push({dis[i.first][j],i.first});
                }
                if(j>0){
                    if(dis[i.first][j]>dis[x.second][j-1]){
                        dis[i.first][j]=dis[x.second][j-1];
                        q.push({dis[i.first][j],i.first});
                    }
                }
            }
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    cin>>b>>e;
    
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra();
    ll ans=1e18;
    for(int i=0;i<=k;i++){
        ans=min(ans,dis[e][k]);
    }
    cout<<ans;
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
