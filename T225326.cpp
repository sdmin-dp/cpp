#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=4e4+5;
ll n;
vector<pair<ll,ll>> g[N];
ll ans=-1e12,k;
ll dis[N];
void bfs(ll x,ll fa){
    queue<pair<ll,ll>> q;
    q.push({x,fa});
    while(!q.empty()){
        pair<ll,ll> t=q.front();
        q.pop();
        for(auto i:g[t.first]){
            ll v=i.first,w=i.second;
            if(v!=t.second){
                dis[v]=max(dis[v],dis[t.first]+w);
                if(dis[v]>ans){
                    ans=dis[v];
                    k=v;
                }
            }
        }
    }
}
void dfs(ll x,ll fa,ll dis){
    if(dis>ans){
        k=x;
        ans=dis;
    }
    for(auto i:g[x]){
        ll v=i.first;
        if(v==fa) continue;
        dfs(v,x,dis+i.second);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    bfs(1,0);
    ans=-1e12;
    dfs(k,0,0);
    cout<<ans;
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