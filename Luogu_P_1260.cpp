#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n,m;
vector<pair<ll,ll>> g[N];
vector<ll> dis(N,-1e12);
vector<ll> vis(N);
ll cnt[N];
bool SPFA(){
    queue<ll> q;
    dis[0]=0;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        vis[x]=0;
        for(auto i:g[x]){
            if(dis[i.first]<dis[x]+i.second){
                dis[i.first]=dis[x]+i.second;
                if(!vis[i.first]){
                    cnt[i.first]++;
                    vis[i.first]=1;
                    if(cnt[i.first]>n+1) return 0;
                    q.push(i.first);
                }
            }
        }
    }
    return 1;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,-w});
    }
    for(int i=1;i<=n;i++) g[0].push_back({i,0});
    bool flag=SPFA();
    if(!flag) cout<<"NO SOLUTION";
    else for(int i=1;i<=n;i++) cout<<dis[i]<<el;
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