#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2500+5;
ll n,m;
vector<ll> g[N];
pair<ll,ll> a[N];
ll dp[N][N][2];
ll len[N];
void dfs(ll u){
    dp[u][1][1]=a[u].first-a[u].second;
    dp[u][1][0]=a[u].first;
    dp[u][0][0]=0;
    len[u]=1;
    for(auto v:g[u]){
        dfs(v);
        for(int i=len[u];i>=0;i--){
            for(int j=1;j<=len[v];j++){
                if(i>=1){
                    dp[u][i+j][1]=min(dp[u][i+j][1],dp[u][i][1]+min(dp[v][j][1],dp[v][j][0]));
                }
                dp[u][i+j][0]=min(dp[u][i+j][0],dp[u][i][0]+dp[v][j][0]);
            }
        }
        len[u]+=len[v];
    }
}
void solve(){
    cin>>n>>m;
    cin>>a[1].first>>a[1].second;
    for(int i=2;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        ll x;cin>>x;
        g[x].push_back(i);
    }
    memset(dp,0x3f,sizeof(dp));
    dfs(1);
    ll ans=0;
    for(int i=n;i>=0;i--){
        if(min(dp[1][i][0],dp[1][i][1])<=m) {
            ans=i;
            break;
        }
    }
    cout<<ans<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("permit.in","r",stdin);
    // freopen("permit.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}