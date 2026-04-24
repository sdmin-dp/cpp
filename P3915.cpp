#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k;
vector<vector<ll>> g;
bool ans=1;
ll dfs(ll u,ll fa){
    if(ans==0) return -1;
    if(g[u].empty()) return 1;
    ll child=0;
    for(auto v:g[u]){
        if(v==fa) continue;
        child+=dfs(v,u);
    }
    if(child+1==k) return 0;
    if(child+1<k) return child+1;
    ans=0;return -1;
}
void solve(){
    cin>>n>>k;
    ans=1;
    g.reserve(n+1);
    g.resize(n+1);
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(n%k!=0){
        cout<<"NO"<<el;
        return;
    }
    if(k==1){
        cout<<"YES"<<el;
        return;
    }
    dfs(1,0);
    if(ans) cout<<"YES"<<el;
    else cout<<"NO"<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        n=k=0;
        g.clear();
        solve();
    }
    return 0;
}