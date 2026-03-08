#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m,t;
map<pair<ll,ll>,ll> mp;
vector<pair<ll,ll>> g[N];
deque<ll> dq;
ll cur[N];
void dfs(ll x){
    
}
void solve(){
    cin>>t>>n>>m;
    if(t==1){
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            mp[{x,y}]=i;
            mp[{y,x}]=-i;
            g[x].push_back({y,i});
            g[y].push_back({x,i});
        }
    }
    else{
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            mp[{x,y}]=i;
            g[x].push_back({y,i});
        }
    }
    for(int i=1;i<=n;i++){
        if(!g[i].empty()){
            dfs(i);
            break;
        }
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