#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,q;
ll a[N];
ll gcd(ll a,ll b){
    if(b==0) return 0;
    return gcd(b,a%b);
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=q;i++){
        ll op,l,r;
        cin>>op>>l>>r;
        if(op==2){
            cout<<r-l+1<<el;
        }else{
            a[l]=r;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("resonance.in","r",stdin);
    freopen("resonance.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}