#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
const ll inf=-1e12;
ll n;
vector<pair<ll,ll>> g[N];
ll ans,k,b,e;
ll pre[N];
vector<ll> path;
void dfs(ll x,ll fa,ll dis){
    pre[x]=fa;
    if(dis>ans) k=x,ans=dis;
    for(auto i:g[x]){
        if(i.first!=fa){
            dfs(i.first,x,dis+i.second);
        }
    }
    ans=inf;
    dfs(1,0,0);
    b=k;
    ans=-1e12;
    dfs(k,0,0);
    e=k;
    ll cur=e;
    while(cur!=b){
        path.push_back(cur);
        cur=pre[cur];
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