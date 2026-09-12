#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e1+5;
ll n,a[N][N];
bool vis[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void dfs(ll x,ll y)
{
	for(int i=0;i<4;i++)
	{
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx<=n+1&&xx>=0&&yy<=n+1&&yy>=0&&!vis[xx][yy]&&a[xx][yy]==0)
		{
			a[xx][yy]=-1;
			vis[xx][yy]=1;
			dfs(xx,yy);
		}
	}
}
void solve()
{
	cin>>n;
	vis[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(0,0);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==-1)
			{
				cout<<0;
			}
			if(a[i][j]==0)
			{
				cout<<2;
			}
			if(a[i][j]==1)
			{
				cout<<1;
			}
			cout<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	solve();
	return 0;
}
