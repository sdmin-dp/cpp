#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
// 总重量 100005
const ll m=100005;
//偏移之后的0值
const ll zero=50005;
ll n;
ll dp[N];
pair<ll,ll> a[N];
ll val(ll x){return (x+50000);}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    memset(dp,-0x3f,sizeof(dp));
    dp[zero]=0;
    for(int i=1;i<=n;i++){
        ll w=a[i].first-a[i].second;
        ll v=a[i].second+a[i].first;
        //如果是正数，那么倒着就是j-w<=j,就要倒着遍历
        if(w>=0) for(int j=m;j>=w;j--) if(dp[j-w]!=-4485090715960753727) dp[j]=max(dp[j],dp[j-w]+v);
        else for(int j=w;j<=m;j++) 
    }
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