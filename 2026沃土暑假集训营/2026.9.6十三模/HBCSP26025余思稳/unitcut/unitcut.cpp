#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m;
ll a[N],b[N];
void solve(){
    cin>>n>>m;
    // if(n==1){
    //     cin>>a[1];
    //     for(int i=1;i<=m;i++){
    //         cin>>b[i];
    //         cout<<a[1]+b[i]<<" ";
    //     }
    //     return;
    // }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    ll gcd=abs(a[2]-a[1]);
    for(int i=3;i<=n;i++){
        gcd=__gcd(gcd,abs(a[i]-a[1]));
    }
    for(int i=1;i<=m;i++){
        cout<<__gcd(gcd,a[1]+b[i])<<" ";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("unitcut.in","r",stdin);
    freopen("unitcut.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}