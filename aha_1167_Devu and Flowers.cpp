#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll p=1000000007;
ll n,m;
ll a[N];
ll cnt,sum;
ll cnm(ll n,ll m){
    m=min(n-m,m);
    ll res=0;
    for(int i=n;i>=m;i--) res*=i;
    for(int i=1;i<=m;i++) res/=i;
    return res;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<cnm(sum,m)%p;
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