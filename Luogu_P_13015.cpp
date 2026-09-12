#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+5;
ll n,m;
pair<ll,ll> a[N];
ll dp[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].second;
        a[i].first=i;
    }
    m=n;
    for(int i=1;i<=n;i++){
        for(int j=a[i].first;j<=m;j++){
            dp[j]=max(dp[j],dp[j-a[i].first]+a[i].second);
        }
    }
    cout<<dp[m];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}