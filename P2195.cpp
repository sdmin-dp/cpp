#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
vector<int>g[N];
int n,m,q,f[N],d[N],v[N],L,P;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int u,int p,int s){
    if(s>L)L=s,P=u;
    for(int v:g[u])if(v!=p)dfs(v,u,s+1);
}
int get_d(int u){
    L=-1;dfs(u,-1,0);
    L=-1;dfs(P,-1,0);
    return L;
}
void solve(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)f[i]=i;
    while(m--){
        int u,v;cin>>u>>v;
        g[u].push_back(v);g[v].push_back(u);
        int fu=find(u),fv=find(v);
        if(fu!=fv)f[fu]=fv;
    }
    for(int i=1;i<=n;i++){
        int r=find(i);
        if(!v[r])d[r]=get_d(i),v[r]=1;
    }
    while(q--){
        int o,x,y;cin>>o>>x;
        if(o==1)cout<<d[find(x)]<<"\n";
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
    cin.tie(0);
    
    return 0;
}
