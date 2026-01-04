#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+10;
ll n,m,ans;
char a[N][N];
bool vis[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct node
{
	ll x,y;
};
queue<node> q;
void bfs()
{

	while(!q.empty())
	{
		node tot=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			ll xx=tot.x+dx[i],yy=tot.y+dy[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]&&a[xx][yy]>='1')
			{
				q.push({xx,yy});
				vis[xx][yy]=1;
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{	
			if(a[i][j]>='1'&&!vis[i][j])
			{
				q.push({i,j});
				vis[i][j]=1;
				ans++;
				bfs();
			}
		
		}
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}
