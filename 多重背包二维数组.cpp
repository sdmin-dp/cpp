#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+5;
ll n,m,w[N],v[N],s[N],dp[N][N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i]>>s[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=s[i]&&k*w[i]<=j;k++){
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
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