#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,b;
vector<pair<ll,ll>> g[N];
vector<pair<ll,ll>> g2[N];
ll dis1[N],dis2[N];
void SPFA(){
    queue<ll> q;
    q.push(b);
    dis1[b]=0;
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        for(auto v:g[x]){
            if(dis1[v.first]>dis1[x]+v.second){
                dis1[v.first]=dis1[x]+v.second;
                q.push(v.first);
            }
        }
    }
}
void SPFA2(){
    queue<ll> q;
    q.push(b);
    dis2[b]=0;
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        for(auto v:g2[x]){
            if(dis2[v.first]>dis2[x]+v.second){
                dis2[v.first]=dis2[x]+v.second;
                q.push(v.first);
            }
        }
    }
}
void solve(){
    cin>>n>>m>>b;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g2[v].push_back({u,w});
    }
    memset(dis1,0x3f,sizeof(dis1));
    memset(dis2,0x3f,sizeof(dis2));
    SPFA();
    SPFA2();
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dis1[i]+dis2[i]);
    }
    cout<<ans;
}
int main() {
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