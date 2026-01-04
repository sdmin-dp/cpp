#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n,m;
vector<ll> g[N];
bool vis[N];
void dfs(ll x){
    vis[x]=1;
    cout<<x<<" ";
    bool flag=0;
    for(auto i:g[x]){
        if(!vis[i]){
            flag=1;
            dfs(i);
            cout<<x<<" ";
        }
    }
    // if(flag) 
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
    dfs(1);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}