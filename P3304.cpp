#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
ll n;
vector<pair<ll,ll>> g[N];
bool book[N];
ll ans=-1e12,k;
ll pre[N];
void dfs(ll x,ll fa,ll dis){
    if(dis>ans){
        k=x;
        ans=dis;
    }
    for(auto i:g[x]){
        ll v=i.first;
        if(v==fa) continue;
        pre[v]=fa;
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
    dfs(1,0,0);
    ans=-1e12;
    dfs(k,0,0);
    
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