#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;//n->点数,m->边数
vector<ll> g[N];
ll idx=0;//时间戳
bool flag[N];//点i是割点的话，flag[i]=1,反之则不是割点
//特色数组
ll root;
ll num[N];//i节点的时间戳
ll low[N];//i节点当前可以回到的最早时间戳
//核心！！！dfs来啦
void dfs(ll x,ll fa){//x->当前节点编号,fa->当前节点的爸爸(生成树角度)
    ll child=0;//孩子个数
    idx++;
    num[x]=idx;//记录时间戳
    low[x]=idx;//刚开始还没算就是自己（初始化）
    for(auto i:g[x]){
        if(num[i]==0){//说明没被访问过（这里是当vis用的）
            //从生成树的角度来说，此时i为x的儿子
            child++;
            dfs(i,x);//继续dfs
            //维护low数组
            low[x]=min(low[x],low[i]);
            //1.当前点不是根节点，2.low[i]>=num[x]（说明我的儿子不能不通过我上到我的头上）
            if(fa!=0&&low[i]>=num[x]){
                flag[x]=1;
            }
            //如果当前节点是根节点，在生成树中必须要有两个儿子，根节点才是割点（一个点断了儿子成根节点就没事呀）
            if(fa==0&&child>=2){
                flag[x]=1;
            }
        }
        else if(i!=fa){
            //如果节点i被访问过并且不受当前节点的父亲，则说明i为x的祖先，要更新当前节点的low
            //i都已经是x的祖先了，肯定是可以到的
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
    for(int i=1;i<=n;i++){
        if(!num[i]){
            root=i;
            dfs(i,0);
        }
    }
    //从一开始开始dfs
    //输出割点
    for(int i=1;i<=n;i++) if(flag[i]==1) cout<<i<<el;
}
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
