#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll mod=1e9+7;
ll n,k,d;
ll dp[N][2];
void solve(){
    cin>>n>>k>>d;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min((ll)i,k);j++){
            if(j>=d) dp[i][1]=(dp[i][1]+dp[i-j][0]+dp[i-j][1])%mod;
            else dp[i][1]=(dp[i][1]+dp[i-j][1])%mod,dp[i][0]=(dp[i][0]+dp[i-j][0])%mod;
        }

    }
    cout<<dp[n][1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin)#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll mod=1e9+7;
ll n,k,d;
ll dp[N][2];
void solve(){
    cin>>n>>k>>d;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min((ll)i,k);j++){
            if(j>=d) dp[i][1]=(dp[i][1]+dp[i-j][0]+dp[i-j][1])%mod;
            else dp[i][1]=(dp[i][1]+dp[i-j][1])%mod,dp[i][0]=(dp[i][0]+dp[i-j][0])%mod;
        }

    }
    cout<<dp[n][1];
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
};
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}