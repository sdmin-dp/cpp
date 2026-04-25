#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define el '\n'
const ll N=1e5+5;
ll n,q;
ll a[N];
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=q;i++){
        ll l,r,x;
        cin>>l>>r>>x;
        for(int j=l;j<=r;j++){
            a[j]=x;
        }
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}