#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,q;
ll d[N];
vector<ll> g[N];
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        if(i==fa) continue;
        d[i]+=d[x];
        dfs(i,x);
    }
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=q;i++){
        ll x,y;
        cin>>x>>y;
        d[x]+=y;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<d[i]<<" ";
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