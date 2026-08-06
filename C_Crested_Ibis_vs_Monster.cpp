#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll h,n;
pair<ll,ll> a[N];
ll dp[N];
void solve(){
    cin>>h>>n;
    ll mx=0;
    for(int i=1;i<=n;i++){ 
        cin>>a[i].first>>a[i].second;
        mx=max(mx,a[i].second);
    }
    ll ans=1e12;
    memset(dp, 0x3f, sizeof dp);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=a[i].first;j<=h+mx;j++){
            dp[j]=min(dp[j],dp[j-a[i].first]+a[i].second);
            if(j>=h){
                ans=min(dp[j],ans);
            }
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