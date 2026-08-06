#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
map<ll,ll> cnt;
ll dp[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        cnt[x]++;
    }
    dp[1]=cnt[1];
    for(int i=2;i<=N-5;i++){
        dp[i]=max(dp[i-1],dp[i-2]+(cnt[i]*i));
    }
    cout<<dp[N-5];
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