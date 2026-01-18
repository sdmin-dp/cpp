#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
string s,t;
ll n,k;
ll p[N];

ll qpow(ll a,ll b,ll p){
    ll res=1;
    while(b){
        if(b%2==1) res=res*a%p;
        a=a*a%p;
        b/=2;
    }
    return res;
}
void solve(){
    cin>>n>>k;
    cin>>s;
    
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