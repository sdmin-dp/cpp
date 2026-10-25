#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
map<ll,ll> p;
void prime(ll x){
    for(ll i=2;i*i<=x;i++){
        while(x%i==0){
            x/=i;
            p[i]++;
        }
    }
    if(x>1) p[x]++;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        prime(i);
    }
    for(auto i:p){
        cout<<i.first<<" "<<i.second<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}