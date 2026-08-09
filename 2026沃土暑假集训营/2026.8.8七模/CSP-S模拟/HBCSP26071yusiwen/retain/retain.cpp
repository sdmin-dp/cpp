#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2000+5;
ll n,m;
vector<ll> g[N];
ll a[N];
ll dp[N][N];
ll len[N];
void dfs(ll u,ll fa){
    dp[u][1]=a[u];
    len[u]=1;
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u);
        ll maxj=min(m,len[u]+len[v]);
        for(ll j=maxj;j>=1;j--){
            ll maxk=min(j-1,len[v]);
            ll mink=max(0ll,j-len[u]);
            for(int k=mink;k<=maxk;k++){
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
            }
        }
        len[u]+=len[v];
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<dp[1][m];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("retain.in","r",stdin);
    freopen("retain.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}