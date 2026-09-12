#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,b;
ll a[N];

void solve(){
    cin>>n>>b;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        cout<<abs(a[1]-b);
        return;
    }
    n++;
    a[n]=b;
    sort(a+1,a+n+1);
    ll ans=a[2]-a[1];
    for(int i=3;i<=n;i++){
        ans=__gcd(ans,a[i]-a[i-1]);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}