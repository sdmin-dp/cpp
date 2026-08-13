#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m,s,l;
vector<pair<ll,ll>> g[N];
ll ans=0;
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({s,0});
    while(!q.empty()){
        auto x=q.front();
        if(x.second>l){
            ans++;
            break;
        }
        for(auto i:g[x.first]){
            q.push({i.first,x.second+i.second});
        }
    }
}
void solve(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin>>l;
    bfs();
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("radius.in","r",stdin);
    freopen("radius.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}