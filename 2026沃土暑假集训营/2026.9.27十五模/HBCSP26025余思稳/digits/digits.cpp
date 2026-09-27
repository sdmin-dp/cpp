#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
void solve(){
    cin>>n>>k;
    if(n==0) cout<<1;
    ll ans=0;
    while(n>0){
        ans++;
        n/=k;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("digits.in","r",stdin);
    // freopen("digits.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}