#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
vector<pair<ll,ll>> g[N];
ll color[N];
void dfs(ll x,ll fa,ll len){
    if(len%2==1) color[x]=1-color[1];
    else color[x]=color[1];
    for(auto i:g[x]){
        if(i.first==fa) continue;
        dfs(i.first,x,len+i.second);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    color[1]=1;
    dfs(1,0,0);
    for(int i=1;i<=n;i++) cout<<color[i]<<el;
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