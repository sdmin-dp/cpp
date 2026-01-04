#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
char a[N][N];
ll dx[]={0,1,0,-1,-1,-1,1,1},dy[]={1,0,-1,0,-1,1,-1,1};
bool vis[N][N];
ll cnt;
void dfs(ll x,ll y){
	for(int i=0;i<8;i++){
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&!vis[xx][yy]&&a[xx][yy]=='W'){
			vis[xx][yy]=1;
			dfs(xx,yy);
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='W'&&!vis[i][j]){
				vis[i][j]=1;
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r",stdin);
//  freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}

