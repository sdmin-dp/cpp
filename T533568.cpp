#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
bool check(ll n,ll x){
    return (n%x==0);
}
void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=1;pow(i,k)<=n;i++){
        if(check(n,pow(i,k))){
            ans=i;
        }
    }
    cout<<ans<<el;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}