#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=200+5;
const ll inf=0x7f7f7f7f7f7f7f7fLL;
ll n,m,k;
ll a[N][N];
ll dp[2][N][N];
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=0;i<=m;i++) for(int j=0;j<=m;j++) dp[0][i][j]=dp[1][i][j]=inf;
    for(int i=1;i<=n;i++){
        ll v=i%2,u=(i-1)%2;
        for(int j=1;j<=m;j++){
            dp[v][j][m]=inf;
            for(int t=0;t<m;t++){
                if(i==1){
                    if(j>1){
                        ll tj=j+t;
                        if(tj>m) tj-=m;
                        dp[v][j][t]=inf;
                        dp[v][j][t]=min(dp[v][j][t],dp[v][j-1][t]+a[i][tj]);
                    }
                    else{
                        ll tj=j+t;
                        if(tj>m) tj-=m;
                        dp[v][j][t]=inf;
                        dp[v][j][t]=min(dp[v][j][t],a[i][tj]+t*k);               
                    }
                }else{
                    if(j>1){
                        ll tj=j+t;
                        if(tj>m) tj-=m;
                        dp[v][j][t]=inf;
                        dp[v][j][t]=min(dp[v][j][t],dp[u][j][m]+a[i][tj]+t*k);
                        dp[v][j][t]=min(dp[v][j][t],dp[v][j-1][t]+a[i][tj]);
                    }else{
                        ll tj=j+t;
                        if(tj>m) tj-=m;
                        dp[v][j][t]=inf;
                        dp[v][j][t]=min(dp[v][j][t],dp[u][j][m]+a[i][tj]+t*k);
                    }
                }
                dp[v][j][m]=min(dp[v][j][m],dp[v][j][t]);
            }
        }
    }
    cout<<dp[n%2][m][m];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("carousel.in","r",stdin);
   	freopen("carousel.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}