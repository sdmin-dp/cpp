#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const double b20=20.0/100.0;
const double b30=30.0/100.0;
const double b50=50.0/100.0;
ll a,b,c;
void solve(){
    cin>>a>>b>>c;
    ll ans=a*b20+b*b30+c*b50;
    cout<<ans;
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