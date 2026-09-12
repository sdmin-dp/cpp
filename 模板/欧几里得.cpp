#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll gcd(ll a,ll b){
    while(b!=0){ 
        ll t=a%b;
        a=b;
        b=t;
    }
}
void solve(){
    ll x,y;
    cin>>x>>y;
    cout<<gcd(x,y);
}

int main() {
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