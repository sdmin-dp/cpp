#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
ll n;
ll a[N],b[N],c[N];
ll dp[N][2][2];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<n;i++) cin>>c[i];
    dp[1][0][0]=dp[1][0][1]=a[1];
    dp[1][1][0]=dp[1][1][1]=b[1];
    for(int i=2;i<=n;i++){
        dp[i][0][0]=max(dp[i-2][1][0]+a[i-1]+a[i]-c[i-2],dp[i-1][1][0]+a[i]-c[i-1]);
        dp[i][1][0]=max(dp[i-2][0][0]+b[i-1]+b[i]-c[i-2],dp[i-1][0][0]+b[i]-c[i-1]);
        dp[i][0][1]=max(dp[i-2][1][1]+a[i-1]+a[i]-c[i-2],dp[i-1][1][1]+a[i]-c[i-1]);
        dp[i][1][1]=max(dp[i-2][0][1]+b[i-1]+b[i]-c[i-2],dp[i-1][0][1]+b[i]-c[i-1]);
        if(i>=3){
            dp[i][0][1]=max(dp[i][0][1],dp[i-3][1][0]+a[i-2]+a[i-1]+a[i]-c[i-3]);
            dp[i][1][1]=max(dp[i][1][1],dp[i-3][0][0]+b[i-2]+b[i-1]+b[i]-c[i-3]);
        }
    }
    cout<<max({dp[n][0][1],dp[n][0][0],dp[n][1][0],dp[n][1][1]});}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("skyway.in","r",stdin);
    freopen("skyway.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}