#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e4+5;
ll n,m;
pair<ll,ll> a[N];
ll dp[N];
void solve(){
    cin>>n>>m;
    ll mx=0;m--;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        mx=max(a[i].first,mx);
    }
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=m+a[i].first;j>=a[i].first;j--){
            dp[j]=max(dp[j],dp[j-a[i].first]+a[i].second);
            ans=max(ans,dp[j]);
        }
    }
    cout<<ans;
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