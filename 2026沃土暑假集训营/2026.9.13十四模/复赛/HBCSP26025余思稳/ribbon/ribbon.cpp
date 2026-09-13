#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,a,b;
void solve(){
    cin>>n>>a>>b;
    ll t1=n/4,t2=n%4;
    ll ans1=n*a,ans2=t1*t1*b+t2*a;
    cout<<max(ans1,ans2);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ribbon.in","r",stdin);
    freopen("ribbon.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}