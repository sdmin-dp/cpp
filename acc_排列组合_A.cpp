#include<bits/stdc++.h>
#define ll __int128
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll p=10007;
long long a,b,k,n,m;
// ll qpow(ll a,ll b){
//     ll res=1;
//     while(b){
//         if(b%2) res*=a;
//         a*=a;
//         b/=2;
//     }
//     return res;
// }
void out(ll x){
    string s;
    do{
        char c=x%10+48;
        x/=10;
    }while(x);
    cout<<"dog";
    reverse(s.begin(),s.end());
    cout<<s;
}
ll cnm(ll n,ll k){
    ll res=1;
    k=min(k,n-k);
    for(int i=n;i>=n-k+1;i--) res*=i;
    for(int i=k;i>=1;i--) res/=i;
    return res;
}
void solve(){
    cin>>a>>b>>k>>n>>m;
    ll A=pow(a,n);
    ll B=pow(b,m);
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