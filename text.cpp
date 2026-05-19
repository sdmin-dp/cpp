#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,u,v,f[100005][30],dep[100005];
vector<vector<int>> g;
void dfs(ll x,ll fa){
    dep[x]=dep[fa]+1;f[x][0]=fa;
    for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
    for(auto i:g[x]) if(i!=fa) dfs(i,x);
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(v,u);
    for(int i=20;i>=0;i--)
        if(dep[f[u][i]]>=dep[v])
            u=f[u][i];

    if(u==v) return u;

    for(int k=20;k>=0;k--)
        if(f[u][k]!=f[v][k])
            u=f[u][k],v=f[v][k];
    return f[u][0];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin>>n>>q;g.resize(n+3);
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1,a,b,c,d,_1,_2;i<=q;i++){
		cin>>a>>b>>c>>d,_1=lca(a,b),_2=lca(c,d);
		// cout<<_1<<' '<<_2<<'\n';
		if(dep[_1]>=dep[_2]){
            if(_1==lca(c,_1)||_1==lca(d,_1)){
                cout<<"Y\n";continue;
            }
        }
		else{
			swap(a,c);swap(b,d);swap(_1,_2);
			if(_1==lca(c,_1)||_1==lca(d,_1)){cout<<"Y\n";continue;}
		}
		cout<<"N\n";
	}
	return 0;
}