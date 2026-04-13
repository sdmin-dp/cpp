#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
void solve(){
    scanf("%lld",&n);
    for(ll i=sqrt(n);i>=1;i--){
        if(n%i) printf("%lld不是%lld的因数",i,n);
        else if(__gcd(i,n/i)!=1) printf("%lld和%lld的最小公倍数不是%lld",i,n/i,n); 
        else printf("%lld和%lld是的",i,n/i);
    }
    
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}