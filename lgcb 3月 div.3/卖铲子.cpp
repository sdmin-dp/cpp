#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
void solve(){
    cin>>n>>m;
    ll sqr=sqrt(n);
    ll ans;
    for(ll i=1;i<=min(sqr,m);i++){
        if(n%i==0) ans=max({ans,i,n/i});
        cerr<<ans;
    }
    cout<<n/ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("shovel.in","r",stdin);
    // freopen("shovel.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}