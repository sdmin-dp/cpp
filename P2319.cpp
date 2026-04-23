#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
ll n,m;
bool vis[N];
ll match[N],rematch[N];
vector<ll> g[N];
bool dfs(ll u){
    for(auto i:g[u]){
        if(!vis[i-m]){
            vis[i-m]=1;
            if(!match[i-m]||dfs(match[i-m])){
                match[i-m]=u;
                rematch[u]=i-m;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[i].push_back(x+m);
        g[i].push_back(y+m);
    }
    ll cnt=0;
    for(int i=1;i<=m;i++){
        memset(vis,0,sizeof vis);
        if(!dfs(i)) break;
        cnt++;
    }
    cout<<cnt<<el;
    for(int i=1;i<=cnt;i++){
        cout<<rematch[i]<<el;
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