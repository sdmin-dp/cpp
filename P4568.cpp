#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e4+5;
ll n,m,k;
ll b,e;
vector<pair<ll,ll>> g[N];
void dijkstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    1
}
void solve(){
    cin>>n>>m>>k>>b>>e;
    for(int i=1;i<=n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u+1].push_back({v+1,w});
        g[v+1].push_back({u+1,w});
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