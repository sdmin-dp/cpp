#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m,s,t;
vector<pair<ll,ll>> g[N];
ll dis[N];
void dijkstra(){
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
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back({v,1});
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()!=0){
            sort(g[i].begin(),g[i].end());
            g[i][0].second=0;
        }
    }
    dijkstra();
    cout<<(dis[t]>=4557430888798830399?-1:dis[t]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}