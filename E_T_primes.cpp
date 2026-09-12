#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
bool isprime(ll x){
    if(x<2) return 0;
    for(ll i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
void solve(){
    ll n;
    cin>>n;
    ll k=sqrt(n);
    if(k*k==n&&isprime(k)) cout<<"YES";
    else cout<<"NO";
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