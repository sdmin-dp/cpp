#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll lcm(ll x,ll y){
    return x/__gcd(x,y)*y;
}
void solve(){
    cin>>n;
    ll lcm;
    cin>>lcm;
    for(int i=2;i<=n;i++){
        ll x;cin>>x;
        lcm=lcm(lcm,x);
    }
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