#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e1+5;
struct node{
	ll x,y,z,step;
};
ll dx[]={0,0,1,0,0,-1};
ll dy[]={-1,0,0,1,0,0};
ll dz[]={0,1,0,0,-1,0};
ll n,m,h,t;
bool a[N][N][N];
void bfs(){
	queue<node> q;
	q.push({0,0,0,0});
	while(!q.empty()){
		ll tx=q.front().x;
		ll ty=q.front().y;
		ll tz=q.front().z;
		ll stp=q.front().step;
		q.pop();
		if(tx==n-1&&ty==m-1&&tz==h-1){
			if(stp<=t) cout<<stp;
			else cout<<-1;
			return;
		}
		for(int i=0;i<6;i++){
			ll xx=tx+dx[i];
			ll yy=ty+dy[i];
			ll zz=tz+dz[i];
			if(xx>=0&&yy>=0&&zz>=0&&xx<n&&yy<m&&zz<h&&!a[xx][yy][zz]){
				a[xx][yy][zz]=1;
				q.push({xx,yy,zz,stp+1});
			}
		}
	}
	cout<<-1;
}
void solve(){
	cin>>n>>m>>h>>t;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(int k=0;k<h;k++) cin>>a[i][j][k];
	bfs();
	cout<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r".stdin);
//  freopen("xxx.out","w".stdout);
    ll T=1;
  	cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

