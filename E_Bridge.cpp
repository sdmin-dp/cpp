#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll root;
ll idx=0;
bool flag[N];
ll num[N];
ll low[N];
vector<pair<ll,ll>> sorted;
void dfs(ll x,ll fa){
    ll child=0;
    idx++;
    num[x]=idx;
    low[x]=idx;
    for(auto i:g[x]){
        if(num[i]==0){
            dfs(i,x);
            low[x]=min(low[x],low[i]);
            if(low[i]>num[x]){
                sorted.push_back({x,i});
            }
        }
        else if(i!=fa){
            low[x]=min(low[x],num[i]);
        }
    }
    return;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    root=1;
    dfs(1,root);
    cout<<sorted.size();
}
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
