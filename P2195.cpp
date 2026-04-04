#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const int N=3e5+5;
vector<int>g[N];
ll n,m,q;
ll f[N],d[N],v[N];
ll L,P;
ll find(ll x){
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void dfs(int u,int p,int s){
    if(s>L) L=s,P=u;
    for(int v:g[u]) if(v!=p) dfs(v,u,s+1);
}
int get_d(int u){
    L=-1;
    dfs(u,-1,0);
    L=-1;
    dfs(P,-1,0);
    return L;
}
void solve(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)f[i]=i;
    while(m--){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        ll fu=find(u),fv=find(v);
        if(fu!=fv) f[fu]=fv;
    }
    // ... 在输入 m 条边后 ...
for(int i = 1; i <= n; i++) {
    int root = find(i);
    if(!v[root]) {
        d[root] = get_d(root); // 确保从当前连通块的某个点开始搜
        v[root] = 1;
    }
}
    for(int i=1;i<=n;i++){
        int r=find(i);
        if(!v[r]){
            d[r]=get_d(i);
            v[r]=1;
        }
    }
    while(q--){
        int o,x,y;cin>>o>>x;
        if(o==1) cout<<d[find(x)]<<el;
        else{
            cin>>y;
            int fx=find(x),fy=find(y);
            if(fx!=fy){
                d[fy]=max({d[fx],d[fy],(d[fx]+1)/2+(d[fy]+1)/2+1});
                f[fx]=fy;
            }
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
