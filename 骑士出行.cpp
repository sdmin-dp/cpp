#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e2+5;
struct node{
	ll x,y,step;
};
ll dx[]={1,2,2,1,-1,-2,-2,-1},dy[]={-2,-1,1,2,-2,-1,1,2};
ll n,bx,by,ex,ey;
bool vis[N][N];
void bfs(){
	queue<node> q;
	vis[bx][by]==1;
	q.push({bx,by,0});
	while(!q.empty()){
		ll tx=q.front().x;
		ll ty=q.front().y;
		ll stp=q.front().step;
		q.pop();
		if(tx==ex&&ty==ey){
			cout<<stp;
			return;
		}
		for(int i=0;i<8;i++){
			ll xx=tx+dx[i],yy=ty+dy[i];
			if(xx>=0&&yy>=0&&xx<n&&yy<n&&!vis[xx][yy]){
				vis[xx][yy]=1;
				q.push({xx,yy,stp+1});
			}
		}
	}
	cout<<-1;
}
void solve(){
	cin>>n;
	cin>>bx>>by;
	cin>>ex>>ey;
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

