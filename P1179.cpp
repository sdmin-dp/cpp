#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll ans=0;
ll count(ll x){
    string s=to_string(x);
    ll cnt=0;
    for(auto i:s) if(i=='2') cnt++;
    return cnt;
}
void solve(){
    ll l,r;
    cin>>l>>r;
    for(ll i=l;i<=r;i++){
        ans+=count(i);
    }
    cout<<ans;
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