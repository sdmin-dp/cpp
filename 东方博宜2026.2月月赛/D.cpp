#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll MAXN=5005;
const ll MAXM=1e5+5;
ll n,m;
ll x[MAXN];
ll c[MAXM];
ll dp[MAXN];
void solve(){
    if(!(cin>>n>>m))return;
    for(int i=1;i<=n;i++) cin>>x[i];
    sort(x+1,x+n+1);
    for(int i=1;i<=m;i++) cin>>c[i];
    for(int i=m-1;i>=1;i--){
        c[i]=min(c[i],c[i+1]);
    }
    for(int i=1;i<=n;i++) dp[i]=1e18;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            ll width=x[i]-x[j]+1;
            dp[i]=min(dp[i],dp[j-1]+c[width]);
        }
    }
    cout<<dp[n]<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}
