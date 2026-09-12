#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll l,n,mn,mx;
void solve(){
    cin>>l>>n;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        mn=max(mn,min(x,l+1-x));
        mx=max(mx,max(x,l+1-x));
    }
    cout<<mn<<" "<<mx;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}