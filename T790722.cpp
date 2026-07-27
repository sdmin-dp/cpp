#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e7+5;
ll prime[N];
bool isprime[N];
void init(){
    isprime[0]=isprime[1]=1;
    for(int i=1;i<=1e7;i++){
        if(isprime[i]) continue;
        prime[i]=i;
        for(int j=2;i*j<=1e7;j++){
            prime[i*j]*=i;
            isprime[i*j]=1;
        }
    }
}
void solve(){
    ll x,y;
    cin>>x>>y;
    ll gcd=prime[__gcd(x,y)];
    ll ans=prime[x]/gcd*prime[y]/gcd;
    // cerr<<gcd<<" "<<prime[x]<<" "<<prime[y]<<el;
    cout<<ans<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    for(int i=1;i<=1e7;i++) prime[i]=1; 
    init();
    while(T--){
        solve();
    }
    return 0;
}