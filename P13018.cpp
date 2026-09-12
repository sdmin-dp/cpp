#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll OFFSET=50000;          // 最大差值偏移
const ll MAXD=100000+5;         // dp数组大小
ll n;
ll dp[MAXD];
pair<ll,ll> a[105];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=0;i<MAXD;i++) dp[i]=-1e15;
    dp[OFFSET]=0; // 差值为0时总和为0

    for(int i=1;i<=n;i++){
        ll w=a[i].first-a[i].second; // 差值
        ll v=a[i].first+a[i].second; // 总和
        if(w>=0){
            for(int j=MAXD-1;j>=w;j--){
                if(dp[j-w]>-1e14) dp[j]=max(dp[j],dp[j-w]+v);
            }
        }else{
            for(int j=0;j<MAXD+w;j++){
                if(dp[j-w]>-1e14) dp[j]=max(dp[j],dp[j-w]+v);
            }
        }
    }

    if(dp[OFFSET]<0) cout<<-1<<el;
    else cout<<dp[OFFSET]<<el;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}