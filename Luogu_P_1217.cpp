#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e8+5;
ll l,r;
bool zs(ll x){
    if(x<2) return 0;
    for (ll i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
bool ishuiwen(ll x){
    ll y=x,z=0;
    while(x){
        z=z*10+x%10;
        x/=10;
    }
    return z==y;
}
void solve(){
    cin>>l>>r;
    if(l%2==0) l++;
    for(int i=l;i<=r;i+=2){
        if(ishuiwen(i)&&zs(i)){
            cout<<i<<"\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}