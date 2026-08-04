#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e4+5;
vector<ll> G[N];
bool vis[N];
void dfs(ll u){
    vis[u]=1;
    for(auto v:G[u])
        if(!vis[v])
            dfs(v);
}
void solve(){
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    if(n!=m){
        cout<<"NO"<<el;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO"<<el;
            return;
        }
    }
    cout<<"FHTAGN!"<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
