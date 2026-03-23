#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll p=10007;
ll a,b,k,n,m;
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2) res=res*a%p;
        a=a*a%p;
        b/=2;
    }
    return res;
}
void out(ll x){
    string s;
    do{
        char c=x%10+48;
        x/=10;
        s=s+c;
    }while(x);
    reverse(s.begin(),s.end());
    cout<<s;
}
ll cnm(ll n,ll k){
    ll res=1;
    k=min(k,n-k);
    for(int i=0;i<k;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
void solve(){
    cin>>a>>b>>k>>n>>m;
    ll A=qpow(a,n);
    ll B=qpow(b,m);
    out(cnm(k,m)*A*B%p);
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