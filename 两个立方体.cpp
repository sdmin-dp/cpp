#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
bool check(ll x){
    for(ll i=1;i*i<=x/i;i++){
        if(i*i*i==x){
            return 1;
        }
    }
    return 0;
}
void solve(){
    cin>>n;
    for(ll i=1;i<=n/2;i++){
        ll j=n-i;
        if(check(i)&&check(j)){
            cout<<"YES"<<el;
            return;
        }
    }
    cout<<"NO"<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
