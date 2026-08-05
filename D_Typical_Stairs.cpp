#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll mod=1000000007;
ll n,m;
ll a[N],dp[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        dp[a[i]]--;
    }
    if(dp[1]==-1&&dp[2]==-1){
        cout<<0;
        return;
    }
    else if(dp[1]==-1) dp[2]=1;
    else if(dp[2]==-1) dp[1]=1;
    else dp[1]=1,dp[2]=2;
    for(int i=3;i<=n;i++){
        if(dp[i]==-1) continue;
        else if(dp[i-1]==-1&&dp[i-2]==-1){
            cout<<0;
            return;
        }
        else if(dp[i-2]==-1) dp[i]=dp[i-1];
        else if(dp[i-1]==-1) dp[i]=dp[i-2];
        else dp[i]=(dp[i-1]+dp[i-2])%mod; 
    }
    cout<<dp[n];
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