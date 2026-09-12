#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=300+5;
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
        ll maxj=min(m+1,len[u]+len[v]);
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
    for(int v=1;v<=n;v++){
        ll u,w;
        cin>>u>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        a[v]=w;
    }
    dfs(0,-1);
    cout<<dp[0][m+1];
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