#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a;
ll ans=0;
void solve(){
    cin>>a;
    for(ll i=10;i<=a;i*=10) ans+=a/i;
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}