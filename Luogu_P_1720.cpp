#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=50+5;
ll n;
ll f[N];
void solve(){
    cin>>n;
    f[1]=f[2]=1;
    for(int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    printf("%.2f",f[n]*1.0);
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