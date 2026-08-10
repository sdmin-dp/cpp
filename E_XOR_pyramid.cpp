#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e3+5;
ll n;
ll a[N];
ll dp[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][i]=a[i];
    }
    for(int len=2;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            ll r=l+len-1;
            if(l==r) dp[l][r]=a[l];
            else dp[l][r]=dp[l][r-1]^dp[l+1][r];
        }
    }
    for(int len=1;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            ll r=l+len-1;
            dp[l][r]=max({dp[l][r],dp[l+1][r],dp[l][r-1]});
        }
    }
    ll m;
    cin>>m;
    for(int i=1;i<=m;i++){
        ll l,r;cin>>l>>r;
        cout<<dp[l][r]<<el;
    }
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