#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
bool prime(ll x){
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
string s;
void solve(){
    cin>>s;
    ll ans=0;
    for(int i=1;i<s.size();i++){
        ll x=(s[i-1]-48)*10+(s[i]-48);
        if(prime(x)) ans+=x;
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