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
        sum+=a[i].second;
    }
    cin>>m;
    for(int i=1;i<=n;i++){
        for(int j=1e5;j>=a[i].second;j--){
            dp[j]=max(dp[j-a[i].second]+a[i].first,dp[j]);
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
    cout<<max(dp[m],1ll);
    ll mn=0x3f3f3f;
    for(int i=m+1;i<=sum;i++){
        mn=min(mn,dp[i]);
    }
    // cout<<max(1ll,mn)<<'\n';
    // if(mx==-1){
    //     cout<<"inf";
    // }else cout<<mx;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("pack.in","r",stdin);
    // freopen("pack.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}