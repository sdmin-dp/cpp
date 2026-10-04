#include<bits/stdc++.h>
using namespace std;
#define ll __int128
#define el '\n'
const ll N=1e5+5;
inline ll read128(){
    char c=getchar();
    ll ret=0;
    while(!isdigit(c)) c=getchar();
    do{ret=ret*10+c-'0';}while(isdigit(c=getchar()));
    return ret;
}
void print128(ll x){
    string s;
    while(x){
        s.push_back('0'+x%10);
        x/=10;
    }
    reverse(s.begin(),s.end());
    cout<<s;
}
ll n;
map<ll,ll> mp;
ll _gcd(ll a,ll b){
    if(b==0) return a;
    return _gcd(b,a%b);
}
void yuefen(ll &a,ll &b){
    ll gcd=_gcd(a,b);
    a/=gcd;b/=gcd;
}
void tongfen(ll &a1,ll &b1,ll &a2,ll &b2){
    ll gcd=_gcd(b1,b2);
    ll B1=b2/gcd,B2=b1/gcd;
    a1*=B1,a2*=B2,b1*=B1,b2*=B2;
}
void fenjie(ll a,ll b){
    if(b==0||a==0) return;
    ll a1=a,b1=b,a2=1,b2=(b+a-1)/a;
    mp[b2]++;
    tongfen(a1,b1,a2,b2);
    ll a3=a1-a2,b3=b2;
    yuefen(a1,b2);
    yuefen(a3,b3);
    fenjie(a3,b3);
}
void solve(){
    n=read128();
    for(int i=1;i<=n;i++){
        ll a,b;
        a=read128();b=read128();
        yuefen(a,b);
        fenjie(a,b);
    }
    ll mx=0,mxid=0,mn=1e12,mnid=0;
    for(auto i:mp){
        if(i.second>mx) mx=i.second,mxid=i.first;
        if(i.second<mn) mn=i.second,mnid=i.first;
    }
    print128(mxid);
    cout<<" ";
    print128(mnid);
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