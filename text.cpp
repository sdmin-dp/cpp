#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans[3],n,m,vis[10005];vector<vector<ll>> v;
bool dfs(ll x,ll color){
	vis[x]=color;
	ans[color]++;
	for(auto i:v[x]){
		if(vis[i]==vis[x]) return 0;
		if(!vis[i]){
			dfs(i,3-color);
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;v.resize(n+5);
	for(int i=0,x,y;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	// ll cnt=0;
	// for(int i=1;i<=n;i++){
	// 	ans[1]=ans[2]=0;
	// 	if(!vis[i]&&!dfs(i,1)){
	// 		cout<<"Impossible";
	// 		return 0;
	// 	}
	// 	cnt+=min(ans[1],ans[2]);
	// }
	// cout<<cnt;
	// return 0;
}
