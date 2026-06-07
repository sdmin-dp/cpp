#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll mod=9901;
ll a,b;
map<ll,ll> mp;
ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y%2) res=res*x%mod;
        y/=2;
        x=x*x%mod;
    }
    return res;
}
void fun(ll n){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
    if(n>1) mp[n]++;
}
void solve(){
    cin>>a>>b;
    fun(a);
    ll ans=1;
    for(auto i:mp){
        i.second*=b;
        if((i.first-1)%mod!=0){
            ll x=qpow(i.first,i.second+1)-1;
            ll y=qpow(i.first-1,mod-2);
            ans=ans*x%mod*y%mod;
        }else{
            ans=ans*(i.second+1)%mod;
        }
    }
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