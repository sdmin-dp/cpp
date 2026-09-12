#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
bool color[N];
vector<ll> g[N];
ll cnt;
bool dfs(ll x,ll fa){
    bool flag=0;
    for(auto i:g[x]) if(i!=fa&&dfs(i,x)) flag=1;
    if(!color[x]&&flag) cnt++;
    return (color[x]||flag);
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>color[i];
    for(int i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(color[i]){
            dfs(i,0);
            break;
        }
    }
    cout<<cnt;
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