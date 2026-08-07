#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll mod=1e9+7;
ll n,m;
pair<ll,ll> a[N];
array<ll,3> dp[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    dp[0][2]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i].first;j<=m;j++){
            if(dp[j][0]<dp[j-a[i].first][0]+a[i].second){
                dp[j][0]=dp[j-a[i].first][0]+a[i].second;
                dp[j][1]=dp[j-a[i].first][1]+1;
                dp[j][2]=dp[j-a[i].first][2];
            }else if(dp[j][0]==dp[j-a[i].first][0]+a[i].second){
                if(dp[j][1]>dp[j-a[i].first][1]+1){
                    dp[j][1]=dp[j-a[i].first][1]+1;
                    dp[j][2]=dp[j-a[i].first][2];
                }else if(dp[j][1]==dp[j-a[i].first][1]+1){
                    dp[j][2]=(dp[j][2]+dp[j-a[i].first][2])%mod;
                }
            }
        }
    }
    cout<<dp[m][0]<<" "<<dp[m][1]<<" "<<dp[m][2];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("module.in","r",stdin);
    // freopen("module.out","w",stdout);
    ll T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
