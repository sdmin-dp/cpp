#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll s1[N],s2[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x,y;cin>>x>>y;
        s1[i]=x-y,s2[i]=x+y;
    }
    sort(s1+1,s1+n+1);
    ll ans1=s1[n]-s1[1];
    sort(s2+1,s2+n+1);
    ll ans2=s2[n]-s2[1];
    cout<<max(ans1,ans2);
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