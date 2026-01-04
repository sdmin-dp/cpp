#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n,m;
char a[N][N];
struct node{
	ll x,y;
};
queue<node> q;
ll dx[]={0,1,0,-1,0},dy[]={1,0,-1,0,0};
ll vis[N][N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='#') q.push({i,j});
			
		}
	}
	ll num=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='#'){
				vis[i][j]++;
				vis[i+1][j]++;
				vis[i-1][j]++;
				vis[i][j+1]++;
				vis[i][j-1]++;
			}
			if(a[i][j]!='#'&&a[i+1][j]!='#'&&a[i-1][j]!='#'&&a[i][j+1]!='#'&&a[i][j-1]!='#'){
				num++;
			}
		}
	}
	ll ans=num;
	while(!q.empty()){
		ll xx=q.front().x,yy=q.front().y;
		q.pop();
		a[xx][yy]='.';
		ll cnt=num;
		for(int i=0;i<=4;i++){
			ll xxx=xx+dx[i],yyy=yy+dy[i];
			if(xxx>=1&&xxx<=n&&yyy>=1&&yyy<=m&&a[xxx][yyy]=='.'){
				if(vis[xxx][yyy]-1<=0){
					cnt++;
				}
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
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

