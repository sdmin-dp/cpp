#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,b,e;
vector<pair<ll,ll>> g[N];
ll dis[N];
ll SPFA(){
    queue<ll> q;
    q.push(b);
    dis[b]=0;
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        for(auto v:g[x]){
            if(dis[v.first]>dis[x]+v.second){
                dis[v.first]=dis[x]+v.second;
                q.push(v.first);
            }
        }
    }
    return dis[e];
}
void solve(){
    cin>>n>>m>>b>>e;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    memset(dis,0x3f,sizeof(dis));
    cout<<SPFA()<<el;
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