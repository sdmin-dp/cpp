#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
map<ll,ll> mp;
void solve(){
    ll x;
    cin>>x;
    cout<<mp[x]<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        mp[x]=i;
    }
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}