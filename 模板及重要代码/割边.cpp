/*
只需要将low[i]>=num[x]改为low[i]>num[x]然后改一下输出就好
因为割边是不走这条边连爸爸都回不到了，所以把'='删掉就好啦
*/
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
                // cout<<x<<'-'<<i<<el;
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
    //输出割边（注意输出！！！）
    //还要排序
    sort(sorted.begin(),sorted.end());
    for(auto i:sorted){
        cout<<i.first<<"-"<<i.second<<el;
    }
    if(sorted.empty()){
        cout<<"None";
    }
}
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
