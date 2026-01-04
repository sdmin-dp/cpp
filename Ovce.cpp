#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=25e1+5;
ll n,m;
char a[N][N];
bool vis[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll lcnt,ycnt;
void dfs(ll x,ll y){
	if(a[x][y]=='o') ycnt++;
	else if(a[x][y]=='v') lcnt++;
	for(int i=0;i<4;i++){
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&vis[xx][yy]==0&&a[xx][yy]!='#'){
			vis[xx][yy]=1;
			dfs(xx,yy);
		}
	}
}   
void solve(){
	cin>>n>>m;
	ll lans=0,yans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			lcnt=0,ycnt=0;
			if(vis[i][j]==0&&a[i][j]!='#'){
				vis[i][j]=1;
				dfs(i,j);
				if(ycnt>lcnt) yans+=ycnt;
				else lans+=lcnt;
			}
		}
	}
	cout<<yans<<" "<<lans;
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
