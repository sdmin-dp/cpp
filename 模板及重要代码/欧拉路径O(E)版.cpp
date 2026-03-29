#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll idx[N];
bool vis[N];
vector<ll> res1,res2;
void dfs(ll x){
    while(idx[x]<g[x].size()){
        ll v=g[x][idx[x]].first,u=g[x][idx[x]].second;
        idx[x]++;
        if(!vis[u]){
            vis[u]=1;
            dfs(v);
            res1.push_back(v);
        }
    }
    res2.push_back(x);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back({y,i});
        g[y].push_back({x,i});
    }
    //不写了
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