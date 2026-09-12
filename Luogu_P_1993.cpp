#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e3+5;
ll n,m;
vector<pair<ll,ll>> g[N];
vector<ll> dis(N,1e9);
ll cnt[N];
bool vis[N];
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
            if(dis[i.first]>dis[x]+i.second){
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
        ll op,u,v,w;
        cin>>op>>u>>v;
        if(op==1){
            cin>>w;
            g[v].push_back({u,-w});
        }else if(op==2){
            cin>>w;
            g[u].push_back({v,w});
        }else{
            g[v].push_back({u,0});
            g[u].push_back({v,0});
        } 
    }
    for(int i=1;i<=n;i++) g[0].push_back({i,0});
    if(SPFA()) cout<<"Yes";
    else cout<<"No";
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