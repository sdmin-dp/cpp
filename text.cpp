#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll a,b,c;
ll n,m,k;
ll ans;

ll lcm(ll A,ll B){return A/__gcd(A,B)*B;}
ll lcm(ll A,ll B,ll C){return lcm(lcm(A,B),C);}
ll res1,res2,res3;
void solve(){
    cin>>a>>n;
    cin>>b>>m;
    cin>>c>>k;
    //(a+b)%c==1
    ll x=1;
    while(lcm(a,b)*x%c!=1) x++;
    res1=lcm(a,b)*x;
    //(a+c)%b==1
    x=1;
    while(lcm(a,c)*x%b!=1) x++;
    res2=lcm(a,c)*x;
    //(b+c)%a==1
    x=1;
    while(lcm(b,c)*x%a!=1) x++;
    res3=lcm(a,c)*x;

    ans=res1*n+res2*m+res3*k;

    ll LCM=lcm(a,b,c);
    cout<<ans%LCM;
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