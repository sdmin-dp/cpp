#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e3+5;
ll n;
ll a[N];
ll dp[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            dp[l][r]=min(dp[l][r-1],dp[l+1][r])+a[r]-a[l];
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