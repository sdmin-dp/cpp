#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
const ll M=5e4+5;
ll n,mx,m;
pair<ll,ll> a[N];
ll dp[M];
void solve(){
    cin>>n>>mx>>m;
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i].second;j--){
            dp[j]=max(dp[j],dp[j-a[i].second]+a[i].first);
        }
    }
    for(int i=1;i<=m;i++){
        if(dp[i]>=mx){
            cout<<i<<el;
            return;
        }
    }
    cout<<-1<<el;
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