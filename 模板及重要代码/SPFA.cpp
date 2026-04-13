//一遍过！我可太棒啦（^w^）
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
/*
第一个应该是先写个queue
然后是遍历
松弛：这个点加上边权<dis[i],说明成功
inq判断是否在队列里（优化）
*/
vector<pair<ll,ll>> g[N];
ll dis[N];
ll b,n,m;
bool inq[N];
ll cnt[N];//判断负环专属,记录入队次数
void SPFA(){
    queue<ll> q;
    memset(dis,0x3f,sizeof(dis));
    dis[b]=0;
    q.push(b);
    cnt[b]++;
    inq[b]=1;
    while(!q.empty()){
        auto x=q.front();
        inq[x]=0;
        q.pop();
        for(auto i:g[x]){
            if(dis[x]+i.second<dis[i.first]){
                //松弛成功
                dis[i.first]=dis[x]+i.second;//这个东西一定要写在外面！！！
                if(!inq[i.first]){
                    q.push(i.first);
                    cnt[i.first]++;
                    inq[i.first]=1;
                    if(cnt[i.first]>n){//入队n次，掉！
                        cout<<"The graph has fuhan!";
                        exit(0);
                    }
                }
            }
        }
    }
}
void solve(){
    //b:begin，起点
    //n点数，m边数
    cin>>n>>m>>b;
    for(int i=1;i<=m;i++){
        ll u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    SPFA();
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}