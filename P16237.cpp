#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll color[N];
ll idx;
void dfs(ll x){
    color[x]=idx;
    for(auto i:g[x]) if(!color[i]) dfs(i);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!color[i]){
            idx++;
            dfs(i);
        }
    }
    cout<<idx-1<<" "<<2*(idx-1)/n+(2*(idx-1)%n!=0?1:0);
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