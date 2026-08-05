#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll inf=1e18;
ll n,k;
ll a[N];
ll dp[N];
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=inf;
    }
    dp[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++) dp[i+j]=min(dp[i]+abs(a[i]-a[i+j]),dp[i+j]);
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