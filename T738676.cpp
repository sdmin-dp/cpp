#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n;
ll a[N];
bool ishuiwen(ll x){
    
}
void solve(){
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    a[0]=1;
    for(ll i=1;i<=62;i++){
        a[i]=a[i-1]*2;
    }
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}