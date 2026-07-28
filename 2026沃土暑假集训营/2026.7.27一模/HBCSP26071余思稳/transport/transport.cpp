#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,k;
pair<ll,ll> a[N];
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    ll cur=0;
    ll ans=0;
    for(int i=n;i>=1;i--){
        if(a[i].second-cur<0){
            cur=-(a[i].second-cur);
            continue;
        }
        a[i].second-=cur; 
        ll t=a[i].second/k;
        if(a[i].second%k!=0) t++;
        cur=t*k-a[i].second;
        ans+=2*t*a[i].first;
        // cerr<<t<<" "<<cur<<el;
    }
    cout<<ans;   
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("transport.in","r",stdin);
    freopen("transport.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}