#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e4+5;
ll n;
ll c[N],a[N];
ll dp[N][N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(c+1,c+n+1);
    for(int i=n;i>=1;i--)
        for(int j=1;j<=n;j++)
            for(int k=i;k<=n;k++)
                if(i==1) dp[j][k]=max(dp[j][k],dp[j-1][k-1]+a[1]);
                else dp[j][k]=max(dp[j][k],dp[j-1][k-i]+a[i]+c[n-j+1]-c[j]);
    ll ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i][n]);
    cout<<ans<<endl;
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

