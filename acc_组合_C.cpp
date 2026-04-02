#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll cnm(ll n,ll k) {
    if(k>n-k) k=n-k;
    ll res=1;
    for(ll i=0;i<k;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
void solve(){
    cin>>n>>m;
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