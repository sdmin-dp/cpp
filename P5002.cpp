#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e4+5;
ll n,q,root;
vector<ll> g[N];
ll len[N];
void dfs(ll x,ll fa){
    if(g[x].empty()) return;
    for(auto i:g[x]){
        if(i==fa) continue;
        dfs(i,x);
        len[x]+=len[i];
    }
}
void solve(){
    cin>>n>>root>>q;
    len[1]=1;
    for(int i=2;i<=n;i++){
        len[i]=1;
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(root,0);
    for(int i=1;i<=n;i++){
        for(auto j:g[i]){
            
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