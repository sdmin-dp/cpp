#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,ll> a[N];
ll dp[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    cin>>m;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i].first;j--){
            if(dp[j-a[i].first]+a[i].second!=0){
                dp[j]=max(dp[j-a[i].first]+a[i].second,dp[j]);
            }
        }
    }
    if(dp[m]==0) cout<<1;
    else cout<<dp[m];
    // for(int i=1;i<=m;i++) cout<<dp[i]<<el;
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