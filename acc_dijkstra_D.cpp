#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e4+5;
ll n,m;
ll b[6];
vector<pair<ll,ll>> g[N];
ll dis[N];
ll dist[7][N];
void dijkstra(ll s){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,s});
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
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
void solve(){
    cin>>n>>m;
    cin>>b[2]>>b[3]>>b[4]>>b[5]>>b[6];
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra(1);
    for(int i=1;i<=n;i++) dist[1][i]=dis[i];
    dijkstra(b[2]);
    for(int i=1;i<=n;i++) dist[2][i]=dis[i];
    dijkstra(b[3]);
    for(int i=1;i<=n;i++) dist[3][i]=dis[i];
    dijkstra(b[4]);
    for(int i=1;i<=n;i++) dist[4][i]=dis[i];
    dijkstra(b[5]);
    for(int i=1;i<=n;i++) dist[5][i]=dis[i];
    dijkstra(b[6]);
    for(int i=1;i<=n;i++) dist[6][i]=dis[i];
    ll ans=1e18;
    for(int i1=2;i1<=6;i1++){
        for(int i2=2;i2<=6;i2++){
            for(int i3=2;i3<=6;i3++){
                for(int i4=2;i4<=6;i4++){
                    for(int i5=2;i5<=6;i5++){
                        if(!(i1!=i2&&i1!=i3&&i1!=i4&&i1!=i5&&i2!=i3&&i2!=i4&&i2!=i5&&i3!=i4&&i3!=i5&&i4!=i5)) continue;
                        ll res=dist[1][b[i1]]+dist[i1][b[i2]]+dist[i2][b[i3]]+dist[i3][b[i4]]+dist[i4][b[i5]];
                        ans=min(ans,res);
                    }
                }
            }
        }
    }
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