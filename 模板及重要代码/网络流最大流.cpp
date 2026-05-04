#include <bits/stdc++.h>
using namespace std;
int e[305][305],v[305],t,minn,ans,n,m,f;
struct stu{
	int u,v,w;
}s[305];
void dfs(int u){
	if(f==1) return;
	if(v[u]==1){
		t--;
		return;
	}
	v[u]=1;
	if(u==n){
		for(int i=1;i<=t;i++) minn=min(minn,s[i].w);
		for(int i=1;i<=t;i++){
			e[s[i].u][s[i].v]-=minn;
			e[s[i].v][s[i].u]+=minn;
		}
		f=1;
		return;
	}
	for(int i=1;i<=n;i++){
		if(e[u][i]!=0&&f==0){
			t++;
			s[t].u=u;
			s[t].v=i;
			s[t].w=e[u][i];
			dfs(i);
		}
	}
	t--;
	return;
}
int main(){
	cin >> m >>n;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >>w;
		e[u][v]+=w;
	}
	while(1){
		memset(v,0,sizeof(v));
		minn=INT_MAX;
		t=0;
		f=0;
		dfs(1);
		if(minn==INT_MAX) break;
		else ans+=minn;
	}
	cout << ans;
    return 0;
}
