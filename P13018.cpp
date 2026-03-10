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
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=1;i<=n;i++){
        
    }
    dp[zero]=0;
    for(int i=1;i<=n;i++){
        ll w=a[i].first-a[i].second;
        ll v=a[i].second+a[i].first;
        //如果是正数，那么倒着就是j-w<=j,就要倒着遍历
        if(w>=0) for(int j=m;j>=w;j--) if(dp[j-w]>-4485090715960753727) dp[j]=max(dp[j],dp[j-w]+v);
        //如果是复数，负重量，从小到大，同样是为了防止重复使用（因为依赖右边的旧值）
        else for(int j=0;j<=m+w;j++) if(dp[j-w]>-4485090715960753727) dp[j]=max(dp[j],dp[j-w]+v);
    }
    if(dp[zero]==-4485090715960753727) cout<<0;
    else cout<<dp[zero];
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