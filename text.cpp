#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define el '\n'
const ll N=1e5+5;
ll n;
void solve(){
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        if(x%2026==0) ans++;
    }
    cout<<ans;
}
int mian(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}