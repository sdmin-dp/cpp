#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll mod=9901;
ll n,m;
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}
void solve(){
    cin>>n>>m;
    ll ans=1;
    for(int i=n;i>=max(n-m+1,m+1);i--) ans=ans*i%mod;
    for(int i=1;i<=min(n-m,m);i++) ans=ans*qpow(i,mod-2)%mod;
    cout<<ans;
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