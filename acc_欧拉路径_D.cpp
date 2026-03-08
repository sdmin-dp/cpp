#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
ll n,m,t;
vector<pair<ll,ll>> g[N];
deque<ll> dq;
ll cur[N];
bool vis[N];
void dfs(ll x){
    for(ll &i=cur[x];i<g[x].size();){
        pair<ll,ll> u=g[x][i];
        i++;
        if(vis[abs(u.second)]) continue;
        vis[abs(u.second)]=1;
        dfs(u.first);
        dq.push_front(u.second);
    }
}
void solve(){
    cin>>t>>n>>m;
    if(t==1){
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            g[x].push_back({y,i});
            g[y].push_back({x,-i});
        }
    }
    else{
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            g[x].push_back({y,i});
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            if(g[i].size()!=2){
                cout<<"NO";
                return;
            }
        }
    }
    for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
    for(int i=1;i<=n;i++){
        if(!g[i].empty()){
            dfs(i);
            break;
        }
    }
    if(dq.size()!=m){
        cout<<"NO"<<el;
        return;
    }
    else{
        cout<<"YES"<<el;
        for(auto i:dq) cout<<i<<" ";
        cout<<el;
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