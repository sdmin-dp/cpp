#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll happy[N];
vector<ll> g[N];
bool fa[N];
pair<ll,ll> dp[N];
void dfs(ll u){
    dp[u].first=0;
    dp[u].second=happy[u];
    for(auto v:g[u]){
        dfs(v);
        dp[u].first+=max(dp[v].first,dp[v].second);
        dp[u].second+=dp[v].first;
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>happy[i];
    }
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>v>>u;
        fa[u]=1;
        g[u].push_back(v);
    }
    ll root=0;
    for(int i=1;i<=n;i++){
        if(!fa[i]){
            root=i;
            break;
        }
    }
    dfs(root);
    cout<<max(dp[root].first,dp[root].second);
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