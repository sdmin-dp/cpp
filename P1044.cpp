#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=20+5;
ll n;
ll dp[N];
void solve(){
    cin>>n;
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]+=dp[j-1]+dp[i-j];
        }
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