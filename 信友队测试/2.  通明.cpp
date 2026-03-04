#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e3+5;
ll n,w;
pair<ll,ll> a[N];
ll dp[N];
ll ans;
//second -> id,first -> val
void solve(){
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
        dp[i]=1;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j].first<a[i].first&&abs(a[i].second-a[j].second)<=w){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    for(int i=1;i<=n;i++) cerr<<dp[i]<<" ";
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