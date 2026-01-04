#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e2+10;
char a[N][N];
ll ans=0;
int n,m;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void dfs(ll x,ll y)
{
	for(int i=0;i<4;i++)
	{
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&a[xx][yy]!='.')
		{
			a[xx][yy]='.';
			dfs(xx,yy);
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
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#')
			{
				dfs(i,j);
				ans++;
			}		
		}
	}
	printf("There are %lld ships.",ans);
}
int main()
{
	solve();
	return 0;
}
