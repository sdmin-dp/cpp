#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a1,b1,a2,b2,a3,b3;
void solve(){
    cin>>n>>a1>>b1>>a2>>b2>>a3>>b3;
    ll s1=b1*(n/a1);
    ll s2=b2*(n/a2);
    ll s3=b3*(n/a3);
    if(n%a1>0) s1+=b1;
    if(n%a2>0) s2+=b2;
    if(n%a3>0) s3+=b3;
    cout<<min({s1,s2,s3});
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