#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
// ll sum[N];
ll suma,sumb;
ll cnta,cntb;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll l=1,r=n;
    while(l<=r){
        if(suma<=sumb){
            suma+=a[l++];
            cnta++;
        }else{
            sumb+=a[r--];
            cntb++;
        }
    }
    cout<<cnta<<" "<<cntb;
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