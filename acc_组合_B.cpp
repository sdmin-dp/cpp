#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
//逆元方法：a的p-2次方
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2) res*=a;
        b/=2;
        a=a*a;
    }
    return res;
}
void solve(){
    ll a,p;
    cin>>a>>p;
    if(__gcd(a,p)!=1){
        cout<<""
    }
    cout<<qpow(a,p-2)<<el;
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