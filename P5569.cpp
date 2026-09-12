#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=4e3+5;
ll dp[N][N];
ll m[N][N];
ll n;
ll a[N];
void solve(){
    memset(dp,0x3f,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
        dp[i][i]=0;
        m[i][i]=i;
    }
    for(int len=2;len<=n;len++){
        
        for(int l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            for(ll k=m[l][r-1];k<=m[l+1][r];k++){
                if(dp[l][k]+dp[k+1][r]+a[r]-a[l-1]<dp[l][r]){
                    dp[l][r]=dp[l][k]+dp[k+1][r]+a[r]-a[l-1];
                    m[l][r]=k;
                }
            }
        }
    }
    cout<<dp[1][n];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}