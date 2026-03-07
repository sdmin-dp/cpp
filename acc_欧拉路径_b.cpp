#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
void dfs(ll x){
    for(auto i:g[x]){
        if(!vis[i]){
            vis[i]=1;
            dfs(i);
        }
    }
}
void solve(){
    while(cin>>n>>m){
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

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