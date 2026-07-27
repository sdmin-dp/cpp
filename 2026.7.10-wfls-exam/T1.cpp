#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll mod=1e9+7;
ll n,ans;
ll a[N],s[N],sum1[N],sum2[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++) sum1[i]=sum1[i-1]+s[i];
    reverse(s,s+n+1);sum2[0]=s[0];
    for(int i=1;i<=n;i++) sum2[i]=sum2[i-1]+s[i];                                  
    for(int i=0;i<n;i++)ans=(ans+(sum2[i]-sum1[i])%mod)%mod;
    cout<<ans%mod;
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