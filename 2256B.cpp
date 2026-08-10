#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
ll a[N];
ll dp[N][2];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        if(c=='0') a[i]=0;
        else if(c=='1') a[i]=1;
        else a[i]=2;
    }
    dp[0][0]=dp[0][1]=dp[1][0]=dp[1][1]=dp[2][0]=dp[2][1]=0;
    dp[0][0]=dp[0][1]=1;

    if(a[1]!=2) dp[1][a[1]]=1;
    else dp[1][0]=dp[1][1]=1;

    if(a[2]==2) dp[2][0]=dp[2][1]=1;
    else dp[2][a[2]]=1;

    for(int i=3;i<=n;i++){
        dp[i][0]=dp[i][1]=0;
        if(a[i]==a[i-2]&&a[i]!=2){cout<<0<<el;return;}
        if(a[i]!=a[i-2]&&a[i]!=2&&a[i-2]!=2) dp[i][a[i]]=dp[i-2][a[i-2]];
        if(a[i]==a[i-2]&&a[i]==2) dp[i][0]=dp[i-2][1],dp[i][1]=dp[i-2][0];
        if(a[i]!=a[i-2]&&a[i-2]!=2&&a[i]==2) dp[i][1-a[i-2]]=dp[i-2][a[i-2]];
        if(a[i]!=a[i-2]&&a[i-2]==2&&a[i]!=2) dp[i][a[i]]=dp[i-2][1-a[i]];
    }
    
    cout<<(dp[n][1]+dp[n][0])*(dp[n-1][1]+dp[n-1][0])<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}