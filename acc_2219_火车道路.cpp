#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e5+5;
const ll mxlog=20;
ll n,m,b;
vector<ll> g[N];
ll up[mxlog][N],dep[N];
void dfs(ll x,ll fa){
    dep[x]=dep[fa]+1;
    
}
void solve(){
    cin>>n>>m>>b;
    for(int i=1;i<n;i++){
        ll x,y;
        g[x].push_back(y);
        g[y].push_back(x);
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