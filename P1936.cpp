#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll k;
void solve(){
    cin>>k;
    ll a=1,b=1,c;
    while(a<=k&&b<=k&&c<=k){
        c=a+b;
        a=b,b=c;
    }
    cout<<"m="<<b-a<<el<<"n="<<a<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}