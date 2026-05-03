#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e2+5;
ll n;
ll a[N];
pair<ll,ll> dp[N][N];
ll s[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n+1;i<=2*n;i++)
        a[i]=a[i-n];
    for(int i=1;i<=2*n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++){
            dp[i][j].first=1e18;
        }
    }
    for(int i=1;i<=n*2;i++)
        dp[i][i].first=dp[i][i].second=0;
    for(int i=2;i<=2*n;i++){
        for(int l=1;l+i-1<=n*2;l++){
            ll r=l+i-1;
            for(int k=l;k<r;k++){
                dp[l][r].first=min(dp[l][r].first,dp[l][k].first+dp[k+1][r].first+s[r]-s[l-1]);
                dp[l][r].second=max(dp[l][r].second,dp[l][k].second+dp[k+1][r].second+s[r]-s[l-1]);
            }
        }
    }
    ll ans1=1e18,ans2=0;
    for(int i=1;i<=n;i++){
        ans1=min(ans1,dp[i][i+n-1].first);
        ans2=max(ans2,dp[i][i+n-1].second);
    }
    cout<<ans1<<" "<<ans2;
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