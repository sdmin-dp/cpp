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
ll num[N];//当前时间戳
ll low[N];//可以回到的最早时间戳
vector<pair<ll,ll>> sorted;//存割边的
void dfs(ll x,ll fa){
    ll child=0;//孩子数量（从生成树的角度来说）
    idx++;//时间戳++
    num[x]=idx;
    low[x]=idx;
    for(auto i:g[x]){
        if(num[i]==0){//当前节点还没放问过（时间戳没赋值）
            dfs(i,x);//dfs他
            low[x]=min(low[x],low[i]);//维护这个点能回到的时间戳最早的节点
            if(low[i]>num[x]){//我的儿子
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
