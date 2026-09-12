#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e2+5;
struct node{
	ll x,y,stp;
};
ll n,m;
char a[N][N];
bool vis[N][N];
ll step[N][N];
ll bx1,by1,bx2,by2,ex,ey;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void bfs(){
	queue<node> q;
	vis[ex][ey]=1;
	q.push({ex,ey,0});
	while(!q.empty()){
//		cout<<"you are a dog"<<el;
		ll tx=q.front().x;
		ll ty=q.front().y;
		ll ts=q.front().stp;
		q.pop();
		for(int i=0;i<4;i++){
			ll xx=tx+dx[i],yy=ty+dy[i];
			if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&a[xx][yy]!='#'&&!vis[xx][yy]){
				vis[xx][yy]=1;
				step[xx][yy]=ts+1;
				q.push({xx,yy,ts+1});
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='@') bx1=i,by1=j;
			else if(a[i][j]=='&') bx2=i,by2=j;
			else if(a[i][j]=='F') ex=i,ey=j;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			step[i][j]=1e9;
		}
	}
	bfs();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<step[i][j]<<" ";
//		}
//		cout<<el;
//	}
	ll ans=max(step[bx1][by1],step[bx2][by2]);
	if(ans<=180) cout<<ans;
	else cout<<"Meeting cancelled";
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
