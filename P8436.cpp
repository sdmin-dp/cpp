#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e5+5;
ll n,m,idx;
vector<ll> g[N];
ll dfn[N],low[N];
void dfs(ll x,ll fa){
    low[x]=dfn[x]=++idx;
    
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
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