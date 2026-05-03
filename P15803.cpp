#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<array<ll,3>> g[N];
vector<array<ll,4>> e;
void dijkstra(ll b,ll mx){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,1});
    vector<ll> dis(0,n+1);
    dis[1]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(dis[x.first]>x.second) continue;
        
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w,w2;
        g[u].push_back({v,w,w2});
        g[v].push_back({u,w,w2});
        e.push_back({u,v,w,w2});
    }
    for(int i=1;i<=n;i++){

    }
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