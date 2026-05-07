#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
ll n,m,k;
vector<vector<pair<ll,ll>>> g;
ll eat[N];
ll dist[N][25]; 
ll& dis(ll x,ll y){
    return dist[x][y+10];
}
void solve(){
    scanf("%lld%lld%lld",&n,&m,&k);
    // cin>>n>>m>>k;
    g.clear();
    g.reserve(n+5);
    g.resize(n+5);
    for(int i=1;i<=n;i++) scanf("%lld",&eat[i]);
    for(int i=1;i<=m;i++){
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}