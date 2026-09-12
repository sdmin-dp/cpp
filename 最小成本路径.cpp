#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4e1+10;
ll n,m,sx,sy,ex,ey,ans=LONG_LONG_MAX;
ll stp[N][N];
ll a[N][N];
bool vis[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct node{
	ll x,y,step;
};
deque<node> dq,dqans;
void dfs(ll x,ll y,ll step)
{
	if(step>=ans) return;
	if(x==ex&&y==ey)
	{
		if(ans>step)
		{
			ans=step;
			dqans=dq;
		}
	}
	for(int i=0;i<4;i++)
	{
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]&&(stp[xx][yy]>step+1||stp[xx][yy]==0))
		{
			stp[xx][yy]=a[xx][yy];
			vis[xx][yy]=1;
			dq.push_back({xx,yy,step+a[xx][yy]});
			dfs(xx,yy,step+a[xx][yy]);
			vis[xx][yy]=0;
			dq.pop_back();
		}
	}
}
void solve()
{
	cin>>n>>m;
	sx=1,sy=1;
	ex=n,ey=m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	vis[sx][sy]=1;
	
	dq.push_back({sx,sy,a[sx][sy]});
	dfs(sx,sy,a[sx][sy]);
	for(int i=0;i<dqans.size();i++)
	{
		if(i>0)
		{
			printf("->(%lld,%lld)",dqans[i].x,dqans[i].y);
		}
		else
		{
			printf("(%lld,%lld)",dqans[i].x,dqans[i].y);
		}
	}
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

