#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll a,b,x,y,n;
void solve(){
    cin>>a>>b>>x>>y>>n;
    ll ans=0;
    for(int i=1;i<=min(n/x,a);i++){
        ll other=n-i*x;
        ll j=min(other/y,b);
        ans=max(ans,i+j);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}