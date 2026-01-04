#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e1+5;
ll n,m;
char a[N][N];
bool vis[N][N];
ll bx,by,ex,ey;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll ans=1e9;
void dfs(ll x,ll y,ll step){
	if(step>=ans) return;
	if(x==ex&&y==ey) ans=min(ans,step);
	for(int i=0;i<4;i++){
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&a[xx][yy]!='#'&&!vis[xx][yy]){
			vis[xx][yy]=1;
			dfs(xx,yy,step+1);
			vis[xx][yy]=0;
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	cin>>bx>>by>>ex>>ey;
	vis[bx][by]=1;
	dfs(bx,by,0);
	cout<<(ans==1e9?-1:ans);
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
