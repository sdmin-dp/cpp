#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
array<ll,3> a[N];
array<ll,3> dp[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=max((dp[i-1][1]+a[i][1]),(dp[i-1][2]+a[i][2]));
        dp[i][1]=max((dp[i-1][0]+a[i][0]),(dp[i-1][2]+a[i][2]));
        dp[i][2]=max((dp[i-1][1]+a[i][1]),(dp[i-1][0]+a[i][0]));
    }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]});
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