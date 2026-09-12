#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.first!=y.first) return x.first>y.first;
    else return x.second>y.second;
}
void solve(){
    cin>>n;
    ll cnt=0;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(cmp(a[i],a[j])){
                cnt++;
            }
        }
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