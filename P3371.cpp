#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,b;
ll dis[N];
vector<pair<ll,ll>> g[N];
void SPFA(){
    queue<ll> q;
    for(int i=1;i<=n;i++) dis[i]=(1<<31)-1;
    q.push(b);
    dis[b]=0;
    while(!q.empy)
}
void solve(){
    cin>>n>>m>>b;
    for(int i=1;i<=m;i++){
        ll u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
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