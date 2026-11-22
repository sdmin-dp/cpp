#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el endl
const ll N=1e5+5;

void solve(){
    ll l=1,r=1e9;
    while(l<=r){
        ll mid=(l+r)/2;
        cout<<mid<<el;
        ll f;cin>>f;
        if(f==0) exit(0);
        if(f==1) r=mid-1;
        else l=mid+1;
    }
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}