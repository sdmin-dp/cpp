#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5+5;
ll n,m,t;
ll bx,by,ex,ey;
ll qx,qy;
bool vis[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll cnt;
void dfs(ll x,ll y){
	if(x==ex&&y==ey){
		cnt++;
		return;
	}
	for(int i=0;i<4;i++){
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&!vis[xx][yy]){
			vis[xx][yy]=1;
			dfs(xx,yy);
			vis[xx][yy]=0;
		}
	}
}
void solve()
{
	cin>>n>>m>>t;
	cin>>bx>>by>>ex>>ey;
	for(int i=1;i<=t;i++){cin>>qx>>qy;vis[qx][qy]=1;}
	vis[bx][by]=1;
	dfs(bx,by);
	cout<<cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

