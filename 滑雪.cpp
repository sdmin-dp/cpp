#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
ll a[N][N];
ll f[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll dfs(ll x,ll y){
	if(f[x][y]>1) return f[x][y];
	for(int i=0;i<4;i++){
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&a[xx][yy]<a[x][y]){
			f[x][y]=max(f[x][y],dfs(xx,yy)+1);
		}
	}
	return f[x][y];
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			f[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dfs(i,j);
		}
	}
	ll mx=-1e9;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mx=max(mx,f[i][j]);
		}
	}
	cout<<mx;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r",stdin);
//  freopen("xxx.out","w",stdout);
	ll T=1;
//  cin>>T;
	while(T--){
		solve();
	}
}

