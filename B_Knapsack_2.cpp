#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e2+5;
ll n,m;
pair<ll,ll> a[N];
ll dp[250005];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].second>>a[i].first;
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=250000;j>=a[i].first;j--)
            dp[j]=min(dp[j-a[i].first]+a[i].second,dp[j]);
    for(int j=250000;j>=0;j--){
        if(dp[j]<=m){
            cout<<j;
            return;
        }
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