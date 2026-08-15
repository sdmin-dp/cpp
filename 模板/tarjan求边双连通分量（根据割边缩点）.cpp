#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e5+5;
ll n,m,idx;
vector<ll> g[N];
ll dfn[N],low[N];//dfn:节点被搜到的绝对时间戳; low:节点不经过父边能到达的最小时间戳
vector<pair<ll,ll>> bridge;//记录所有桥边(u,v)
map<pair<ll,ll>,bool> mp;//标记哪些边是桥，用于后续change函数跳过
vector<ll> ans[N];//ans[i]存储第i个边双连通分量包含的所有节点
ll color[N];//标记节点属于哪个边双连通分量

// 核心：Tarjan算法找桥
void dfs(ll x,ll fa){
    low[x]=dfn[x]=++idx;
    bool flag=0;//【关键】处理重边：标记是否已经走过回往父节点的边
    for(auto i:g[x]){
        if(!dfn[i]){//1. 树枝边：未访问过的节点
            dfs(i,x);
            low[x]=min(low[x],low[i]);
            //【判桥法则】low[i] > dfn[x] 意味着i无法回溯到x或其祖先，则x-i是必经之路
            if(low[i]>dfn[x]) bridge.push_back({min(x,i),max(x,i)});
        }
        else if(i==fa){//2. 回到父节点
            if(!flag){//如果是第一次回到父节点，认为是树边回溯，跳过
                flag=1;
                continue;
            }else{//如果第二次及以后回到父节点，说明x与fa之间有重边，按返祖边处理
                low[x]=min(low[x],dfn[i]);
            }
        }else{//3. 返祖边：访问到了祖先节点，更新low
            low[x]=min(low[x],dfn[i]);
        }
    }
}

// 核心：划分边双连通分量
void change(ll x){
    color[x]=idx;//当前DFS覆盖的所有点都属于同一个e-BCC
    for(auto i:g[x]) 
        //【策略】只要这条边不是桥且目标点未染色，就属于同一个分量
        if(!mp[{min(x,i),max(x,i)}]&&!color[i]) change(i);
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // 步骤1：遍历全图（处理不连通情况）找桥
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i,0);
    // 步骤2：将桥存入map方便快速查询
    for(auto &i:bridge) mp[{i.first,i.second}]=1;
    
    idx=0;//复用idx作为颜色（分量编号）计数器
    // 步骤3：DFS遍历，不走桥边，划分出所有边双连通分量
    for(int i=1;i<=n;i++){
        if(!color[i]){
            idx++;
            change(i);
        }
    }
    // 步骤4：整理并输出结果
    cout<<idx<<el;
    for(int i=1;i<=n;i++) ans[color[i]].push_back(i);
    for(ll i=1;i<=idx;i++){
        cout<<ans[i].size()<<" ";
        for(auto &j:ans[i]) cout<<j<<" ";
        cout<<el;
    }
}

int main(){
    // 关闭同步流提升IO效率
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}