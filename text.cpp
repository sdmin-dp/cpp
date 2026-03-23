#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll cnm(ll n,ll k){
    ll res=1;
    k=min(k,n-k);
    for(int i=n;i>=n-k+1;i--) res*=i;
    for(int i=k;i>=1;i--) res/=i;
    return res;
}
void solve(){
    cout<<cnm(10,8);
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