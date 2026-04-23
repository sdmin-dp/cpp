#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
ll n;
ll a[N];
ll dp[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][i]=1;
    }
    for(int len=1;len<=n;len++){
        for(int i=n-len+1;i>=1;i--){
            ll j=i+len-1;
            // dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
            cout<<i<<" "<<j<<el; 
        }
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