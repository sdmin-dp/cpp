#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=(1<<18)+5;
const ll maxn=60;
ll n;
ll a[N];
ll dp[maxn][N];
ll ans=0;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[a[i]][i]=i;
        ans=max(ans,a[i]);
    }
    for(ll i=1;i<=maxn;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j]==0){
                ll k=dp[i-1][j];
                if(k!=0&&k<n&&dp[i-1][k+1]!=0){
                    dp[i][j]=dp[i-1][k+1];
                    ans=max(ans,i);
                }
            }
        }
    }
    cout<<ans;
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}