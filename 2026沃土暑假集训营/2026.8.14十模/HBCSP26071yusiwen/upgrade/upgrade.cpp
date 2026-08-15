#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
const ll M=1e6+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
pair<ll,ll> a[N+5];
ll dp[N+5],dp2[M+5];
void init(){
    for(int i=2;i<=N;i++){
        dp[i]=inf;
        for(int j=1;j<i;j++){
            ll v=i-j;
            ll x=v/j;
            if(x*j==v) dp[i]=min(dp[v]+1,dp[i]);
        }
    }
}
void solve(){
    cin>>n>>m;
    memset(dp2,0,sizeof(dp2));
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].first=dp[a[i].first];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].second;
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i].first;j--){
            dp2[j]=max(dp2[j],dp2[j-a[i].first]+a[i].second);
        }
    }
    cout<<dp2[m]<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("upgrade.in","r",stdin);
    freopen("upgrade.out","w",stdout);
    ll T=1;
    cin>>T;
    init();
    while(T--){
        solve();
    }
    return 0;
}