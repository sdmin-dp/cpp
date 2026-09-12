#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e3+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
vector<pair<ll,ll>> g[N];
ll dis[N][2];
void dijstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,1});
    memset(dis,0x3f,sizeof(dis));
    dis[1][0]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(x.first>dis[x.second][1]) continue;
        for(auto i:g[x.second]){
            if(dis[i.first][0]>x.first+i.second){
                dis[i.first][1]=dis[i.first][0];
                dis[i.first][0]=x.first+i.second;
                q.push({dis[i.first][0],i.first});
                q.push({dis[i.first][1],i.first});
            }else if(dis[i.first][1]>x.first+i.second&&dis[i.first][0]!=x.first+i.second){
                dis[i.first][1]=x.first+i.second;
                q.push({dis[i.first][1],i.first});
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
    dijstra();
    cout<<dis[n][1];
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