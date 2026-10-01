#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n;
ll a[N],b[N],c[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=2;i<=n;i++) cin>>c[i];
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i];
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("skyway.in","r",stdin);
    freopen("skyway.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}