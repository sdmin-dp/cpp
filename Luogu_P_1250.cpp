#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=3e4+5;
ll n,m;
vector<pair<ll,ll>> g[N];
vector<ll> dis(N,-1e12);
vector<bool> inq(N);
ll cnt[N];
bool SPFA(ll b){
    queue<ll> q;
    dis[b]=0;
    q.push(b);
    inq[b]=0;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        inq[x]=0;
        for(auto i:g[x]){
            if(dis[i.first]<dis[x]+i.second){
                dis[i.first]=dis[x]+i.second;
                if(!inq[i.first]){
                    inq[i.first]=1;
                    cnt[i.first]++;
                    if(cnt[i.first]>=n+2) return 0;
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
        // g[v].push_back({u-1,-w});
        g[u-1].push_back({v,w});
        }
    for(int i=0;i<=n;i++) g[n+1].push_back({i,0});
    for(int i=1;i<=n;i++){
        g[i].push_back({i-1,-1});
        g[i-1].push_back({i,0});
    }
    SPFA(n+1);
    cout<<dis[n];
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