#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5000+5;
ll n,d;
ll a[N],c[N];
ll dp[N][N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) dp[i][i]=c[i];
    for(ll len=2;len<=n;len++){
        for(ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            dp[l][r]=min(dp[l][r-1]+c[r],dp[l+1][r]+c[l]);
            if(llabs(a[r]-a[l])<=d){
                if(len>2) dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
                else dp[l][r]=0;
            }
        }
    }
    cout<<dp[1][n];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
kelediamond
*/