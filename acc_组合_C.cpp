#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll mod=9901;
ll n,m;
ll poww(ll a,ll b){
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
    ll a=n/mod,b=m/mod;
    ll ans=cnm(a,b)*cnm(n%mod,m%mod)%mod;
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