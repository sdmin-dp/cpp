#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
ll a[N],b[N];
ll mn=1e12;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        mn=min(mn,b[i]);
    }
    cout<<a[1]*mn<<" ";
    for(int i=2;i<=n;i++) cout<<0<<" ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("rootecho.in","r",stdin);
    freopen("rootecho.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}