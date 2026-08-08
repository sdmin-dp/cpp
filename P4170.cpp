#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=50+5;
ll n;
string s;
ll dp[N][N];
void solve(){
    cin>>s;
    n=s.size();
    s=' '+s;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++) dp[i][i]=1;
    for(ll len=2;len<=n;len++){
        for(ll l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            if(s[l]==s[r]) dp[l][r]=min(dp[l][r-1],dp[l+1][r]);
            for(int k=l;k<=r;k++) dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
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