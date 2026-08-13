#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ll long long
#define el '\n'
const ll N=2e5+5;
const ll inf=0x7f7f7f7f7f7f7f7f;
struct node{
    ll first,second,id;
};
ll n,m,s,l;
vector<node> g[N];
ll dis[N];
ll vis[2 * N];
vector<ll> tmp;
void dijkstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,s});
    memset(dis,0x7f,sizeof(dis));
    dis[s]=0;
    while(!q.empty()){
        ll u=q.top().second;
        q.pop();
        for(auto i:g[u]){
            ll v=i.first,w=i.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
void solve(){
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w,i*2});
        g[v].push_back({u,w,i*2+1});
    }
    cin>>l;
    dijkstra();
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(dis[i]<l) tmp.push_back(i);
        else if(dis[i]==l) ans++;
    }
    memset(vis,0,sizeof(vis));
    for(auto u:tmp){
        for(auto i:g[u]){
            ll v=i.first,w=i.second,ID=i.id;
            if(dis[v]+w==dis[u]) continue;
            ll tid=ID^1;
            if(vis[tid]){
                if(l-dis[u]+vis[tid]<w){
                    ans++;
                }
            }else{
                if(dis[u]+w>l){
                    vis[ID]=l-dis[u];
                    ans++;
                }
            }
        }
    }
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