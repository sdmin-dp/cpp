#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=400+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n;
ll a[N];
ll sum[N];
ll dp[N][N];
void solve(){
    cin>>n;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=a[i]+sum[i-1];
        dp[i][i]=0;
    }
    for(ll len=2;len<=n;len++){
        for(ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            for(int k=l;k<=r;k++){
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+sum[r]-sum[l-1]);
            }
        }
    }
    cout<<dp[1][n];
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