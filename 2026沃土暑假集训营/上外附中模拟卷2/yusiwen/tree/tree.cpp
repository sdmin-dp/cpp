#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

void solve(){
    ll n;
    // vector<vector<ll>> g(n+1);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll u,v;
        cin>>u>>v;
    }
    cout<<0<<" "<<n-3;
    cout<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}