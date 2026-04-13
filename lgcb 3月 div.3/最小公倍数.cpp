#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll ans=1e18;
void solve(){
    cin>>n;
    // cout<<n;
    for(ll i=1;i*i<=n;i++){
        if(n%i) continue;
        if(__gcd(i,n/i)!=1) continue;
        ans=min(ans,max(i,n/i));
        // cout<<"dog";
    }
    cout<<ans;
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