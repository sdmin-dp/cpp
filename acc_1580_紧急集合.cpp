#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5;
vector<vector<int>>e(maxn+2);
vector<int>d(maxn+2,0);
int lca[maxn+2][21];
void dfs(int u,int f){
    d[u]=d[f]+1;
    lca[u][0]=f;
    for(int i=1;i<=19;i++){
        lca[u][i]=lca[lca[u][i-1]][i-1];
    }
    for(auto v:e[u]){
        if(v==f) continue;
        dfs(v,u);
    }
}
int LCA(int u,int v){
    if(d[u]<d[v]){
        swap(u,v);
    }
    for(int i=19;i>=0;i--){
        if(d[lca[u][i]]>=d[v]){
            u=lca[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(int i=19;i>=0;i--){
        if(lca[u][i]!=lca[v][i]){
            u=lca[u][i];
            v=lca[v][i];
        }
    }
    return lca[u][0];
}
int dis(int u,int v){
    return d[u]+d[v]-2*d[LCA(u,v)];
}
int main()
{
    int n,m;
    scanf("%d%d",n,m);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++){
        int a[3];
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        int ans=3*n,ai=0;
        for(int j=0;j<=2;j++){
            int tmp=LCA(a[j],a[(j+1)%3]);
            int t=dis(a[j],a[(j+1)%3])+dis(tmp,a[(j+2)%3]);
            if(ans>t){
                ans=t;
                ai=tmp;
            }
        }
        printf("%d %d\n",ai,ans);
    }
    return 0;
}