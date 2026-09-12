#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=30+5;
ll n,m;
ll dp[N][N];
void solve(){
    cin>>n>>m;
    dp[1][0]=1;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(i==n) dp[i][j]=dp[i-1][j-1]+dp[1][j-1];
            else if(i==1) dp[i][j]=dp[n][j-1]+dp[i+1][j-1];
            else dp[i][j]=dp[i-1][j-1]+dp[i+1][j-1];
        }
    }
    cout<<dp[1][m];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}