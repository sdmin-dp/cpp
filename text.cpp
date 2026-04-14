#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5,maxm=4e5;
vector<vector<int>>e(maxn+2);
int pos[maxn+2],a[maxm+2];
int d[maxn+2];
int lca[22][maxn+2];
void dfs(int u,int f){
    lca[0][u]=f;
    for(int i=1;i<=20;i++){
        lca[i][u]=lca[i-1][lca[i-1][u]];
    }
    for(auto v:e[u]){
        if(v==f) continue;
        d[v]=d[u]+1;
        dfs(v,u);
        pos[u]=min(pos[u],pos[v]);
    }
}
int LCA(int u,int v){
    if(d[u]<d[v]){
        swap(u,v);
    }
    for(int i=20;i>=0;i--){
        if(d[lca[i][u]]>=d[v]){
            u=lca[i][u];
        }
    }
    if(u==v){
        return u;
    }

    for(int i=20;i>=0;i--){
        if(lca[i][u]!=lca[i][v]){
            u=lca[i][u];
            v=lca[i][v];
        }
    }

    return lca[0][u];
}
int dis(int u,int v){
    return d[u]+d[v]-2*d[LCA(u,v)];
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int n,m,r;
    cin>>n>>m>>r;
    for(int i=1;i<n;i++){
        pos[i]=m+2;
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    pos[n]=m+2;

    for(int i=1;i<=m;i++){
        cin>>a[i];
        pos[a[i]]=min(pos[a[i]],i);
    }

    dfs(r,0);

    int last=r;
    long long ans=0;
    for(int i=1;i<=m;i++){
        if(pos[a[i]]==i){
            ans+=dis(last,a[i]);
            last=a[i];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
