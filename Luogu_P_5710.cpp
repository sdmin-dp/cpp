#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
bool is1(ll x){return x%2==0;}
bool is2(ll x){return x>4&&x<=12;}
bool A(ll x){return is1(x)&&is2(x);}
bool Uim(ll x){return is1(x)||is2(x);}
bool B(ll x){return (is1(x)&&!is2(x))||(!is1(x)&&is2(x));}
bool zengmei(ll x){return !is1(x)&&!is2(x);}
void solve(){
    ll n;
    cin>>n;
    cout<<A(n)<<" "<<Uim(n)<<" "<<B(n)<<" "<<zengmei(n)<<el;
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