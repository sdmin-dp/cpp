#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll a,b,c;
void solve(){
    cin>>a>>b>>c;
    ll r=(c-b)/(b-a);
    ll d=(b-a)*(c-b)/(b-a);
    cout<<r*c+d;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ngs.in","r",stdin);
    freopen("ngs.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}