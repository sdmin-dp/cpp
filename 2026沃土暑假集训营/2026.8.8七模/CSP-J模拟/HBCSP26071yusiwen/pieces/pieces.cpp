#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=4e4+5;
const ll mod=1e9+7;
ll n,d;
ll a[N];
ll dp[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=0;
    dp[0]=1;
    for(int i=1;i<n;i++){
        for(int j=a[i+1]+d;j>=a[i];j--){
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
            if(j>=a[i+1]-d) ans=(ans+dp[j])%mod;
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pieces.in","r",stdin);
    freopen("pieces.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}