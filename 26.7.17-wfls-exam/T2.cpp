#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
ll x[N];
ll k=1;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[1]+=k*a[i];
        k=-k;
    }
    for(int i=2;i<=n;i++) x[i]=a[i-1]*2-x[i-1];
    for(int i=1;i<=n;i++) cout<<x[i]<<" ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
