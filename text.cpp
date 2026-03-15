#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll p=1e9;
ll n;
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2) res*=a;
        b/=2;
        a*=a;
    }
    return res;
}
void solve(){
    cin>>n;
    ll a=n/3,b=n%3;
    ll ans;
    if(b==1) ans=(qpow(3,a-1)*4);
    else ans=qpow(3,a);
    cout<<ans<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}