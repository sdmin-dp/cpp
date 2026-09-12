#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    return (x.second-x.first)>(y.second-y.first);
}
ll n;
pair<ll,ll> a[N];
void solve(){
    cin>>n;
    ll cnt=0;
    for(int i=1;i<=2*n;i++){
        cin>>a[i].first;
        cnt+=a[i].first;
    }
    for(int i=1;i<=2*n;i++) cin>>a[i].second;
    sort(a+1,a+2*n+1,cmp);
    for(int i=1;i<=n;i++){
        cnt+=a[i].second-a[i].first;
    }
    cout<<cnt;
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