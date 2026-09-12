#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
const ll mod=1e9+7;
ll n;
ll dp[N];
void solve(){
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    for(int i=5;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4])%mod;
    }
    cout<<dp[n];
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