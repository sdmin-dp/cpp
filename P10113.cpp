#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];

void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll x;
        cin>>x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        ll len,x,lca;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}