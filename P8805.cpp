#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll sum[N];
ll dfs(ll x,ll fa){
    if(g[x].size()==1) return sum[x]=1;
    for(auto i:g[x]){
        if(i!=fa){
            sum[x]+=dfs(i,x);
        }
    }
    return sum[x];
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
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