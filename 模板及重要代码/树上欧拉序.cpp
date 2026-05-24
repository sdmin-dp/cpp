#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
vector<ll> g[N];
ll dep[N];
vector<ll> ans;
void dfs(ll x,ll fa){
    dep[x]=dep[fa]+1;
    ans.push_back(x);
    for(auto i:g[x]){
        if(i==fa) continue;
        dfs(i,x);
        ans.push_back(x);
    }
}
// stack<pair<ll,ll>> s;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // s.push({1,0});
    // while(!s.empty()){
    //     ll x=s.top().first,fa=s.top().second;
    //     s.pop();
    //     dep[x]=dep[fa]+1;
    //     ans.push_back(x);
    //     for(auto i:g[x]){
    //         if(i==fa) continue;
    //         // dfs(i,x);
    //         s.push({i,x});
    //         ans.push_back(x);
    //     }
    // }
    // dfsdeep(1,0);
    dfs(1,0);
    for(auto i:ans) cout<<i<<" ";
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