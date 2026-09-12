#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,ll> a[N];
ll dp[N];
ll sum;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        sum+=a[i].first;
    }
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    cin>>m;
    for(int i=1;i<=n;i++){
        for(int j=1e5;j>=a[i].first;j--){
            dp[j]=min(dp[j-a[i].first]+a[i].second,dp[j]);
        }
    }
    // ll mn,mx=-1;
    // for(int i=0;i<=sum;i++){
    //     if(dp[i]>=m){
    //         mn=i;
    //         break;
    //     }
    // }
    // for(int i=mn;i<=sum+1;i++){
    //     if(dp[i]>m){
    //         mx=i-1;
    //         break;
    //     }
    // }
    cout<<max(dp[m],1ll)<<el;
    ll mn=0x3f3f3f3f;
    for(int i=m+1;i<=sum;i++){
        mn=min(mn,dp[i]);
    }
    if(mn==0x3f3f3f3f) cout<<"inf";
    else cout<<mn-1;
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