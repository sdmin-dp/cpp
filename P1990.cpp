#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
const ll mod=10000;
ll n;
ll a[N];
void solve(){
    cin>>n;
    a[1]=1,a[2]=2,a[3]=5;
    for(int i=4;i<=n;i++){
        a[i]=(2*a[i-1]+a[i-3])%mod;
    }
    cout<<a[n]%mod;
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