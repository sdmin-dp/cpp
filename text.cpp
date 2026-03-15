#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll a,b,c;
ll _a,_b,_c;
ll lcm(ll a,ll b,ll c){
    return a/__gcd(__gcd(a,b),c)*b*c;
}
void solve(){
    cin>>a>>_a;
    cin>>b>>_b;
    cin>>c>>_c;
    ll _=a*b*c+1;
    ll ans=(_a+_b+_c)*_;
    ll LCM=lcm(a,b,c);
    cout<<LCM;
    cerr<<106%3<<" "<<106%5<<" "<<106%7;
    // while(ans>LCM) ans-=LCM;
    // cout<<ans;
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