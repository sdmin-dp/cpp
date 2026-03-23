#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll p=10007;
ll a,b,k,n,m;
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2) res*=a;
        a*=a;
        b/=2;
    }
    return res;
}
ll cnm(ll n,ll k){
    ll res=1;
    k=min(k,n-k);
    for(int ia=n;i>=n-k+1;i--) res*=i;
    for(int i=k;i>=1;i--) res/=i;
    return res;
}
void solve(){
    cin>>a>>b>>k>>n>>m;
    ll r=k-n;
    cout<<cnm(k,r)*qpow(a,k-r)*qpow(b,r)%p;
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