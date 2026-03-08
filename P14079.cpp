#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,a,b,x,y;
void solve(){
    cin>>n>>a>>b;
    while(n--){
        cin>>x>>y;
        if(__gcd(x,y)==1) cout<<min(a,2*b)<<el;
        else cout<<min(2*a,b)<<el;
    }
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