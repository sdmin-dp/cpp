#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll p=10007;
ll n,m;
ll qpow(ll a,ll b,ll p){
    ll res=1;a=a%p;
    while(b){
        if(b&1) res=res*a%p;
        b>>=1;a=a*a%p;
    }
    return res;
}
ll C(ll n,ll m,ll p){
    if(m>n) return 0;
    m=min(m,n-m);
    ll a1=1,a2=1;
    for(int i=1;i<=m;i++){
        a1=a1*(n-i+1)%p;
        a2=a2*i%p;
    }
    return a1*qpow(a2,p-2,p)%p;
}
ll Ls(ll n,ll m,ll p){
    if(m==0) return 1;
    return C(n%p,m%p,p)*Ls(n/p,m/p,p)%p;
}
void solve(){
    cin>>n>>m;
    cout<<Ls(n,m,p)<<endl;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}