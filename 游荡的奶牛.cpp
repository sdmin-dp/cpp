#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
struct node{
	ll x,y,t;
};
ll bx,by,ex,ey,T,n,m;
char a[N][N];
ll f[N][N][20];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void bfs(){
	queue<node> q;
	f[bx][by][0]=1;
	q.push({bx,by,0});
	while(!q.empty()){
		node u=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			ll xx=u.x+dx[i];
			ll yy=u.y+dy[i];
			ll tt=u.t+1;
			if(f[xx][yy][tt]){
				f[xx][yy][tt]+=f[u.x][u.y][u.t];
				continue;
			}
			if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]=='*'||tt>T){
				continue;
			}
			f[xx][yy][tt]+=f[u.x][u.y][u.t];
			q.push({xx,yy,tt});
		}
	}
}
void solve(){
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	cin>>bx>>by>>ex>>ey;
	bfs();
	cout<<f[ex][ey][T];
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
