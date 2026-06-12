#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
vector<ll> g[N];
pair<ll,ll> dp[N];
void dfs(ll u,ll fa){
    dp[u].second=1;
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u);
        dp[u].first+=dp[v].second;
        dp[u].second+=min(dp[v].first,dp[v].second);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll u,sum;cin>>u>>sum;
        for(int i=1;i<=sum;i++){
            ll v;cin>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    dfs(0,-1);
    cout<<min(dp[0].first,dp[0].second);
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