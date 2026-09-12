#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e2+5;
struct node{
	ll x,y,step;
};
ll n,m,a,b;
bool vis[N][N];
ll ans[N][N];
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
ll qx,qy;
queue<node> q;
void bfs(){
	while(!q.empty()){
		ll tx=q.front().x;
		ll ty=q.front().y;
		ll stp=q.front().step;
		q.pop();
		for(int i=0;i<4;i++){
			ll xx=tx+dx[i],yy=ty+dy[i];
			if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&!vis[xx][yy]){
				q.push({xx,yy,stp+1});
				vis[xx][yy]=1;
				if(ans[xx][yy]==0) ans[xx][yy]=stp+1;
				else ans[xx][yy]=min(ans[xx][yy],stp+1);
			}
		}
	}
}
void solve(){
	cin>>n>>m>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>qx>>qy;
		q.push({qx,qy,0});
		vis[qx][qy]=1;
	}
	bfs();
	for(int i=1;i<=b;i++){
		cin>>qx>>qy;
		cout<<ans[qx][qy]<<el;
	}
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
