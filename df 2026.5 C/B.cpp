#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=100+5;
const ll mod=1e9+7;
ll n;
ll cnt0[N],cnt1[N];
bitset<64> b;
ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y%2) res=res*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return res;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        b=x;
        for(int j=0;j<64;j++){
            if(b[j]==0) cnt0[j]++;
            else cnt1[j]++;
        }
    }
    ll ans=0;
    ll last=0;
    for(int i=0;i<64;i++){
        ans=(ans+qpow(2,i)*((cnt0[i]%mod)*(cnt1[i]%mod)%mod))%mod;
    }
    cout<<ans%mod;
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