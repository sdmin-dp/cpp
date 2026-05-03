#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll inf=1e15;
ll n,m;
vector<array<ll,3>> g[N];
vector<array<ll,4>> e;
vector<ll> dijkstra(ll b,ll mx){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,b});
    vector<ll> dis(n+1,inf);
    dis[b]=0;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(dis[x.second]<x.first) continue;
        for(auto i:g[x.second]){
            ll u=x.second,v=i[0],w=i[1],w2=i[2];
            if(w2>mx) continue;
            if(dis[v]>x.first+w){
                dis[v]=x.first+w;
                q.push({dis[v],v});
            }
        }
    }
    return dis;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w,w2;
        g[u].push_back({v,w,w2});
        g[v].push_back({u,w,w2});
        e.push_back({u,v,w,w2});
    }
    ll ans=inf;
    sort(e.begin(),e.end());
    for(int i=0;i<m;i++){
        ll b=e[i][0],u=e[i][1],v=e[i][2];
        vector<ll> d1=dijkstra(1,b);
        vector<ll> dn=dijkstra(n,b);
        if(d1[u]!=inf&&dn[v]!=inf) ans=min(ans,d1[u]+dn[v]);
        swap(u,v);
        if(d1[u]!=inf&&dn[v]!=inf) ans=min(ans,d1[u]+dn[v]);
    }
    cout<<(ans==inf?-1:ans);
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