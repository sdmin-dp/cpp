#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N];
ll sum,h=1e17;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>a[i]>>x;
        h=min(h,a[i]+x);
    }
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=0;i<=n;i++){
        sum+=a[i];
        if(sum>m) break;
        ans=max(ans,i+(m-sum)/h*2);
    }
    cout<<ans;
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