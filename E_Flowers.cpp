#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll mod=1e9+7;
ll t,k;
ll dp[N];
ll sum[N];
void solve(){
    cin>>t>>k;
    dp[0]=1;
    for(int i=1;i<=N;i++){
        dp[i]=(dp[i]+dp[i-1])%mod;
        if(i>=k) dp[i]=(dp[i]+dp[i-k])%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
    }
    for(int i=1;i<=t;i++){
        int l,r;
        cin>>l>>r;
        int ans=(sum[r]-sum[l-1]+mod)%mod;
        cout<<ans<<el;
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