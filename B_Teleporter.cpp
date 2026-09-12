#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
const ll mxlog=60;
ll n,k;
ll a[N];
ll st[65][N];
void solve(){
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        st[0][i]=a[i];
    }
    for(ll j=1;j<=mxlog;j++){
        for(ll i=1;i<=n;i++){
            st[j][i]=st[j-1][st[j-1][i]];
        }
    }
    ll cur=1;
    for(ll i=mxlog;i>=0;i--){
        if((k>>i)&1){
            cur=st[i][cur];
        }
    }
    cout<<cur;
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