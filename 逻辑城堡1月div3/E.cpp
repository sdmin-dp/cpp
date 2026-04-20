#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
map<ll,ll> cnt;
void solve(){
    cnt.clear();
    ll n;
    cin>>n;
    ll mx=0;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        cnt[a-i]++;
        mx=max(mx,a-i);
    }
    ll ans=0;
    for(auto i:cnt){
        ans+=i.second/2+i.second%2;
    }
    cout<<ans<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}