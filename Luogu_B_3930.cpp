#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
ll n;
ll a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,greater<ll>());
    if(n>32) n=32;
    ll mx=-1e9;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            mx=max(mx,a[i]&a[j]);
        }
    }
    cout<<mx;
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