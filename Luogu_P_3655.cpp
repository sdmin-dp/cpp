#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n,q,s,t;
ll a[N],f[N];
ll sum;
ll get(ll x){
    if(f[x]>0) return (-s)*f[x];
    else return (-t)*f[x];
}
void solve(){
    ll l,r,k;
    cin>>l>>r>>k;
    sum-=get(l);
    f[l]+=k;
    sum+=get(l);
    if(r!=n){
        sum-=get(r+1);
        f[r+1]-=k;
        sum+=get(r+1);
    }
    cout<<sum<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    cin>>n>>q>>s>>t;
    for(int i=0;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) f[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++) sum+=get(i);
    //cin>>T;
    while(q--){
        solve();
    }
    return 0;
}