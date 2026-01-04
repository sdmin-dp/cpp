#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+5;
ll n,m,w[N],v[N],dp[2][N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j<w[i]) dp[1][j]=dp[0][j];
            else dp[1][j]=max(dp[0][j],dp[0][j-w[i]]+v[i]);
        }
        for(int j=1;j<=m;j++) dp[0][j]=dp[1][j];
    }
    cout<<dp[0][m];
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