#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
ll n,m,s,t;
vector<ll> g[N],g2[N];
ll vis[N],vis2[N];
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        g[v].push_back(u);
        g2[u].push_back(v);
    }
    cin>>s>>t;
    vis[t]=1;
    queue<ll> q;
    q.push(t);
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(auto i:g[u]) vis[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        for(auto j:g2[i]){
            if(!vis[j]){
                vis[i]=2;
                break;
            }
        }
    }
    queue<pair<ll,ll>> p;
    p.push({s,0});
    while(!p.empty()){
        auto [u,w]=p.front();
        p.pop();
        if(u==t){
            cout<<w;
            return;
        }
        for(auto v:g2[u]){
            if(vis[v]==1&&!vis2[v]){
                p.push({v,w+1});
                vis2[v]=1;
            }
        }
    }
    cout<<-1;
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