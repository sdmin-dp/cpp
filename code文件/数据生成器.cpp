#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll mod2=1e9+1;
const ll mod=1e5+1;
ll n,m;
void solve(){
    n=rand()%mod,m=rand()%mod;
    cout<<n<<" "<<m<<el;
    for(int i=1;i<=n;i++){
        ll x=rand()%mod2;
        cout<<x<<" ";
    }
    cout<<el;
    for(int i=1;i<=m;i++){
        ll l=rand()%mod2,r=rand()%mod2;
        cout<<l<<" "<<r<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(time(0));
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}