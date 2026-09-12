#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,t;
string s;
ll x;
vector<ll> a,b;
void solve(){
    cin>>n>>t;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(s[i]=='1') a.push_back(x);
        else b.push_back(x);
    }
    sort(b.begin(),b.end());
    ll cnt=0;
    for(int i=0;i<a.size();i++){
        ll pos=upper_bound(b.begin(),b.end(),a[i]+2*t)-lower_bound(b.begin(),b.end(),a[i]);
        cnt+=pos;
    }
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}