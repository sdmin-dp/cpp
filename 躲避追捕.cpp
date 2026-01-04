#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e2+5;
ll n,m;
char a[N][N];
bool vis[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void dfs(ll x,ll y){
	for(int i=0;i<4;i++){
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx>=0&&yy>=0&&xx<=n+1&&yy<=m+1&&!vis[xx][yy]&&a[xx][yy]!='#'){
			vis[xx][yy]=1;
			dfs(xx,yy);
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	vis[0][0]=1;
	dfs(0,0);
	ll cnt=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!vis[i][j]&&a[i][j]!='#') cnt++;
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

