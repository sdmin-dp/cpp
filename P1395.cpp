#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e4+5;
ll n;
vector<ll> g[N];
ll len[N];
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        if(i==fa) continue;
        dfs(x,fa);
        len[x]+=len[i];
    }
}
void dfs2(ll x,ll fa){
    for(auto i:g[x]){
        if(i==fa) continue;
        ll lenu=len[x];
        
        len[x]+=len[i];
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x,y;cin>>x>>y;
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