#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5+5;
ll n,m;
char a[N][N];
bool vis[N][N];
ll cnt;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void dfs(ll x,ll y){
	if(x==n&&y==m){
		cnt++;
		return;
	}
	for(int i=0;i<4;i++){
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&a[xx][yy]=='*'&&!vis[xx][yy]){
			vis[xx][yy]=1;
			dfs(xx,yy);
			vis[xx][yy]=0;
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	vis[1][1]=1;
	dfs(1,1);
	cout<<cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
