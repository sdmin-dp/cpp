#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
const ll mod=10007;
ll n;
ll dp[N];
void solve(){
    cin>>n;
    dp[1]=dp[2]=0;dp[3]=1;
    for(int i=4;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod;
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
    cout<<el;
    return 0;
}