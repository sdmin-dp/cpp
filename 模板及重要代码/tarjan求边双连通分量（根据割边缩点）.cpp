#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N],ng[N]; // g: 原图邻接表, ng: 缩点后的新图(树)
ll dfn[N],low[N];       // Tarjan 算法的时间戳与回溯值
ll idx;                 // 全局计数器：先用于 dfn 编号，后用于 color 编号
vector<pair<ll,ll>> bridge; // 存储所有找出的割边
map<pair<ll,ll>,bool> mp;   // 标记割边，用于染色时阻断连接
ll color[N];            // color[i] 表示点 i 属于哪个边双连通分量
// 第一步：DFS 寻找割边
void dfs(ll x,ll fa){
    dfn[x]=++idx;
    low[x]=idx;
    for(auto i:g[x]){
        if(dfn[i]==0){ // 未访问过的节点（树枝边）
            dfs(i,x);
            low[x]=min(low[i],low[x]);
            // 【割边判定】子节点 i 无法通过其他路径回到 x 或 x 以上的祖先
            if(low[i]>dfn[x]) bridge.push_back({x,i});
        }
        // 【关键点】此处通过 i!=fa 忽略父节点。
        // 注意：若原图有重边（x, fa 之间多条边），此逻辑会误判，建议改用边编号判断。
        else if(i!=fa) low[x]=min(low[x],dfn[i]); 
    }
}
// 第二步：Flood Fill 染色（缩点）
void change(ll x){
    color[x]=idx; // 为当前点赋予新的分量编号
    for(auto i:g[x]) {
        // 【核心逻辑】在原图上扩展，但满足两个条件：
        // 1. 当前边不是割边 (通过 mp 判断)
        // 2. 目标点还没有被染色
        if(!mp[{min(x,i),max(x,i)}] && !color[i]) change(i);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // 1. 跑 Tarjan 寻找割边（假设原图连通，否则需循环检查未访问点）
    dfs(1,0);
    // 2. 预处理割边：排序并存入 map，方便 change 函数 O(log E) 判定
    for(auto &i:bridge) if(i.first>i.second) swap(i.first,i.second);
    for(auto &i:bridge) mp[{i.first,i.second}]=1;
    // 3. 染色：将每个边双连通分量缩成一个点
    idx=0; 
    for(int i=1;i<=n;i++){
        if(!color[i]){
            idx++; // 每个新的分量拥有唯一 ID
            change(i);
        }
    }
    // 4. 建立新图：遍历所有割边，连接它们所属的缩点
    for(auto i:bridge){
        ng[color[i.first]].push_back(color[i.second]);
        ng[color[i.second]].push_back(color[i.first]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}

