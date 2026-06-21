#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=50+5;
ll n;
ll a[N],dp[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1]=a[1];
    dp[2]=max(a[1],a[2]);
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    }
    cout<<dp[n];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}