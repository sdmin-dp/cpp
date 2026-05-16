#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
ll xr[N];
map<ll,ll> prime;
map<ll,ll> mp;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    prime[2]=0;
    prime[3]=1;
    prime[5]=2;
    prime[7]=3;
    prime[11]=4;
    prime[13]=5;
    prime[17]=6;
    prime[19]=7;
    prime[23]=8;
    prime[29]=9;
    //2 3 5 7 11 13 17 19 23 29
    for(int i=1;i<=n;i++){
        ll k=0;
        ll x=a[i];
        for(int j=2;j*j<=x;j++){
            while(x%j==0){
                k^=(1<<prime[j]);
                x/=j;
            }
        }
        if(x>1) k^=(1<<prime[x]);
        xr[i]=xr[i-1]^k;
    }
    ll cnt=0;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        cnt+=mp[xr[i]];
        mp[xr[i]]++;
    }
    cout<<cnt;
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