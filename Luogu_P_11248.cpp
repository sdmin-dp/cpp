#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=500+5;
ll dp[2][N][305];
char a[N][N];
ll n,m,x;
void solve(){
    cin>>n>>m>>x;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=x;k++){
                dp[i%2][j][k]=max(dp[(i+1)%2][j][k],dp[i%2][j-1][k]);
                if(a[i][j]=='1') dp[i%2][j][k]++;
                if(k>=1&&a[i][j]=='?') dp[i%2][j][k]=max({dp[i%2][j][k],dp[(i+1)%2][j][k-1]+1,dp[i%2][j-1][k-1]+1});
            }
        }   
    }
    ll ans=0;
    for(int i=0;i<=x;i++) ans=max(ans,dp[n%2][m][i]);
    cout<<ans<<el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}