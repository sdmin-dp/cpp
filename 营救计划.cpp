#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
struct node{
	ll x,y,step;
	bool operator<(const node b) const {
		step<b.step;
	}
};
ll n,m,bx,by,ex,ey;
char a[N][N];
bool vis[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void bfs(){
	priority_queue<node> q;
	vis[bx][by]=1;
	q.push({bx,by,0});
	while(!q.empty()){
		ll tx=q.top().x;
		ll ty=q.top().y;
		ll stp=q.top().step;
		q.pop();
		if(tx==ex&&ty==ey){
			cout<<stp;
			return;
		}
		for(int i=0;i<4;i++){
			ll xx=tx+dx[i],yy=ty+dy[i];
			if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&!vis[xx][yy]&&a[xx][yy]!='#'){
				vis[xx][yy]=1;
				if(a[xx][yy]=='G') q.push({xx,yy,stp+2});
				else q.push({xx,yy,stp+1});
			}
		}
	}
	cout<<"You can't save Mengxin";
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='M') ex=i,ey=j;
			else if(a[i][j]=='@') bx=i,by=j;
		}
	}
	bfs();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r",stdin);
//  freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}

