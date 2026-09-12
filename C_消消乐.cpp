#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=100+5;
ll n;
ll a[N];
ll dp[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll len=1;len<=n;len++){
        for(ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            for(int k=l;k<=r;k++){
                dp[l][r]=max(dp[l][r],dp[l][k-1]+dp[k+1][r]+a[l-1]+a[r+1]);
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
