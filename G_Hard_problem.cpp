#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=1e5+5;
ll n;
void solve(){   
    cin>>n;
    vector<vector<ll>>dp(n+2,vector<ll>(2,inf));
    vector<ll>a(n+2,0);
    vector<vector<string>>s(n+2,vector<string>(2,""));
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=dp[0][1]=0;
    for(int i=1;i<=n;i++){
        cin>>s[i][0];
        s[i][1]=s[i][0];
        reverse(s[i][1].begin(),s[i][1].end());
        for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                if(s[i][k]>=s[i-1][j]){
                    if(k==0) dp[i][k]=min(dp[i][k],dp[i-1][j]);
                    else dp[i][k]=min(dp[i][k],dp[i-1][j]+a[i]);
                }
            }
        }
    }
    ll ans=min(dp[n][0],dp[n][1]);
    if(ans>=inf) cout<<-1<<el;
    else cout<<ans<<el;
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