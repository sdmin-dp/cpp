#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
void dfs(ll x,ll fa){
    dep[x]=dep[fa]+1;
    up[0][x]=fa;
    for(int i=1;i<=mxlog;i++) up[i][x]=up[i-1][up[i-1][x]];
    for(auto i:g[x]) if(i!=fa) dfs(i,x);
}
void solve(){
    
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