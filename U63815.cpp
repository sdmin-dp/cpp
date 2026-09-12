#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll x;
ll n=1,m=1;
void solve(){
    cin>>x;
    while(n<=x){
        ll u=n+m;
        m=n,n=u;
    }
    cout<<"m="<<n-m<<el<<"n="<<m<<el;
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