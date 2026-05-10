#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=4e4+5;
ll n;
vector<pair<ll,ll>> g[N];
ll ans=-1e12,k;
void bfs(ll x,ll fa){
    
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
    dfs(1,0,0);
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