#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll lcs(ll x,ll y){return x/__gcd(x,y)*y;}
void solve(){
    string s,t;
    cin>>s>>t;
    ll n=lcs(s.size(),t.size());
    string ss,tt;
    ll sss=n/s.size(),ttt=n/t.size();
    while(sss--) ss+=s;
    while(ttt--) tt+=t;
    if(ss==tt) cout<<ss;
    else cout<<-1;
    cout<<el;
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