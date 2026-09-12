#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;

void solve(){
    cin>>n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<max(i,n/i);
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