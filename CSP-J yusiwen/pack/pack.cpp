#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,ll> a[N];
ll dp[N];
ll sum1,sum2;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        sum1+=a[i].first;sum2+=a[i].second;
    }
    cin>>m;
    if(sum1==m){
        cout<<sum2<<el<<"inf";
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i].first;j--){
            if(dp[j-a[i].first]+a[i].second!=0){
                dp[j]=max(dp[j-a[i].first]+a[i].second,dp[j]);
            }
        }
    }
    if(dp[m]==0) cout<<1;
    else cout<<dp[m];
    cout<<el;
    cout<<dp[m]+2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pack.in","r",stdin);
    freopen("pack.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}