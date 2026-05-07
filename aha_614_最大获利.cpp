#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
const ll inf=1e12;
struct node{
    ll x,time,cola,food;
    bool operator <(const node b)const {
        return time<b.time;
    }
};
ll n,m,k;
vector<vector<pair<ll,ll>>> g;
ll eat[N];
ll dist[N][25]; 
ll b,e;
ll& dis(ll x,ll y){
    return dist[x][y+10];
}
void dijkstra(){
    priority_queue<node> q;
    q.push({0,b});
    for(int i=1;i<=n;i++) for(int j=-10;j<=10;j++) dis(i,j)=inf;
    memset(dist,0x3f,sizeof(dist));
    dis(b,1)=0;
    while(!q.empty()){
        auto t=q.top();
        q.pop();
        for(auto i:g[t.x]){
            ll fod=t.food,cla=t.cola;
            if(eat[i.first]==1) cla++;
            else fod++;
            ll offset=fod-cla;
            if(dis(i.first,offset)>t.time+i.second){
                dis(i.first,offset)=t.time+i.second;
                q.push({i.first,dis(i.first,offset),cla,fod});
            }
        }
    }
}
void solve(){
    scanf("%lld%lld%lld",&n,&m,&k);
    // cin>>n>>m>>k;
    g.clear();
    g.reserve(n+5);
    g.resize(n+5);
    for(int i=1;i<=n;i++) scanf("%lld",&eat[i]);
    for(int i=1;i<=m;i++){
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin>>b>>e;
    dijkstra();
    ll ans=inf;
    for(int i=-k;i<=k;i++) ans=min(ans,dis(e,i));
    cout<<(ans==inf?-1:ans)<<el;
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}