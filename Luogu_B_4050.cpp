#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
bool isprime(ll x){
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
void solve(){
    cin>>n;
    // cout<<n;
    ll cnt=0;
    ll pw=1;
    bool flag=0;
    while(n>0){
        if(isprime(n)){
            cout<<cnt+1<<el;
            return;
        }
        n-=pw;
        pw*=2;
        cnt++;
    }
    if(n==0) cout<<cnt<<el;
    else cout<<-1<<el;
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