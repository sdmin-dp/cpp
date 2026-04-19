#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll in[N];
ll pre[N];
ll dis[N];
void bfs(){
    queue<pair<ll,ll>> q;
    for(ll i=1;i<=n;i++) if(!in[i]) q.push({i,0});
    while(!q.empty()){
        auto x=q.front();q.pop();
        for(auto i:g[x.first]){
            if(dis[i.first]<x.second+i.second){
                dis[i.first]=x.second+i.second;
                pre[i.first]=x.first;
            }else if(dis[i.first]==x.second+i.second){
                pre[i.first]=min(x.first,pre[i.first]);
            }
            q.push({i.first,dis[i.first]});
        }
    }
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
    ll ans=0,cur=0;
    deque<ll> res;
    for(int i=1;i<=n;i++){
        if(ans<dis[i]){
            ans=dis[i];
            cur=i;
        }
    }
    for(int i=1;i<=n;i++){
        cerr<<pre[i]<<" ";
    }
    cerr<<cur;
    while(!cur){
        res.push_front(cur);
        cur=pre[cur];
    }
    cout<<ans<<el;
    for(auto i:res) cout<<i<<" ";
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