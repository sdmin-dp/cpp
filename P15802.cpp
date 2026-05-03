#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll mod=1e9;
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2) res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}
void solve(){
    ll n;
    cin>>n;
    if(n<3) cout<<n;
    else if(n%3==0) cout<<qpow(3,n/3)%mod;
    else if(n%3==1) cout<<qpow(3,n/3-1)*4%mod;
    else cout<<qpow(3,n/3)*2%mod;
    cout<<el;
    
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