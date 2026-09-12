#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1500+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll dis[N];
bool inq[N];
void SPFA(){
    queue<ll> q;
    memset(dis,~0x3f,sizeof dis);
    q.push(1);
    inq[1]=1;
    dis[1]=0;
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        inq[u]=0;
        for(auto [v,w]:g[u]){
            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    SPFA();
    if(dis[n]==~(0x3f3f3f3f3f3f3f3f)) cout<<-1;
    else cout<<dis[n];
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