#include<bits/stdc++.h>
using namespace std;
#define ll int
#define el '\n'
const ll N=1e4+5;
ll n,m;
ll a[N];
pair<ll,ll> dp[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        dp[i].first=a[i];
        dp[i].second=a[i];
        for(int j=i+1;j<=n;j++){
            dp[j].first=max(dp[j-1].first,a[j]);
            dp[j].second=min(dp[j-1].second,a[j]);
        }
        for(int j=i+1;j<=n;j++){
            if(dp[i].first-dp[j].second<=m){
                cnt++;
                cerr<<i<<" "<<j<<" "<<dp[j].first<<" "<<dp[j].second<<el;
            }
        }
    }
    cout<<cnt;
    
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