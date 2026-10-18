#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
map<char,ll> mp;
string s;
void solve(){
    cin>>s;
    for(auto &j:s) mp[j]++;
    ll ans=0;
    for(auto i:mp){
        ll x=i.second;
        ans+=x*(x+1)/2;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}