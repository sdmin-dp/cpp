#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N = 2e5+5;
ll n,k,a[N];
ll check(ll x){
    ll cnt=0;
    for(ll i=1;i<=n;i++) {
        cnt+=(ll)(ceil(a[i]*1.0/x))-1ll;
    }
    return cnt;
}
void solve() {
    cin>>n>>k;
    for(ll i=1;i<=n;i++) cin>>a[i];
    ll l=1,r=1e9;
    while(l<r){
        ll mid=l+(r-l)/2;
        if(check(mid)<=k) r=mid;
        else l=mid+1;
    }
    cout<<l<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}