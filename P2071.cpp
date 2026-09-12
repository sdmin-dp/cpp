#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=4e4+5;
ll n;
vector<ll> g[N];
bool vis[N];
ll match[N];
bool dfs(ll u){
    for(auto i:g[u]){
        if(!vis[i]){
            vis[i]=1;
            if(!match[i]||dfs(match[i])){
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n;
    n*=2;
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        g[i].push_back(y);
        g[i].push_back(n+y);
        g[i].push_back(x);
        g[i].push_back(n+x);
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        if(dfs(i)) cnt++;
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