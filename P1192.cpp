#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll mod=100003;
ll n,k;
ll dp[N];
void solve(){
    cin>>n>>k;
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i<=k) dp[i]=(dp[i-1]*2)%mod;
        else dp[i]=(dp[i-1]*2-dp[i-k-1])%mod;
    }
    cout<<(dp[n]+mod)%mod;
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