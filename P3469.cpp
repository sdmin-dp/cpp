#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,dfn[100005],low[100005],tot,root,sz[100005],ans[100005];
vector<vector<ll>> e;
void tarjan(ll u){
	dfn[u]=low[u]=++tot;
	sz[u]=1;
	ll child=0,sum=0;
	for(auto v:e[u]){
		if(!dfn[v]){
			tarjan(v);
			sz[u]+=sz[v];
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				child++;
				ans[u]+=sz[v]*(n-sz[v]);
				sum+=sz[v];
				if(u!=root||child>1){
					// cut node logic implicitly handled by ans calculation
				}
			}
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
	ans[u]+=(n-1-sum)*(sum+1)+n-1;
}
void solve(){
    cin>>n>>m;e.resize(n+5);
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(dfn[i]) continue;
		root=i;
		tarjan(i);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<'\n';
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