#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
void solve(){
    cin>>n;
    for(ll i=0;(1<<i)<=n;i++){
        a[i]=(1ll<<i);
    }
    cout<<n<<"=";
    bool flag=1;
    ll x=n;
    for(int i=0;;i++){
        if(n>=a[i]){
            if(flag){cout<<a[i];flag=0;}
            else cout<<'+'<<a[i];
            n-=a[i];
        }
        else{
            if(n>0) cout<<'+'<<n;
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("number.in","r",stdin);
    // freopen("number.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}