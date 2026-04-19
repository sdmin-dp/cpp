#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll in[N];
void bfs(){
    queue<pair<ll,ll>> q;
    for(int i=1;i<=n;i++) if(!in[i]) q.push({i,0});
    ll ans=0;
    while(!q.empty()){
        auto x=q.front();
        ll u=x.first,step=x.second;
        ans=max(ans,step);
        for(auto i:g[u]){
            ll v=i.first,w=i.second;
            q.push({v,step+w});
        }
    }
    cout<<ans;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        in[v]++;
    }
    bfs();
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