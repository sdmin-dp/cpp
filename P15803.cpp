#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<array<ll,3>> g[N];
vector<array<ll,4>> e;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v,w,w2;
        g[u].push_back({v,w,w2});
        g[v].push_back({u,w,w2});
        e.push_back({u,v,w2,});
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