#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
bool isprime(ll x){
    if(x<2) return 0;
    for(ll i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
void solve(){
    cin>>n;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(isprime(i)){
            cnt++;
        }
    }
    cout<<cnt+1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}