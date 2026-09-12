#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e1+5;
ll n,m,h;
ll p;
ll a[N][N][N];
bool vis[N][N][N]; 
ll dx[]={0,0,1,0,0,-1},dy[]={-1,0,0,1,0,0},dz[]={0,1,0,0,-1,0}; 
ll cnt=0;
void dfs(ll x,ll y,ll z){ 
	for(int i=0;i<6;i++){
		ll xx=x+dx[i],yy=y+dy[i],zz=z+dz[i];
		if(xx>=1&&yy>=1&&zz>=1&&xx<=n&&yy<=m&&zz<=h&&!vis[xx][yy][zz]&&abs(a[x][y][z]-a[xx][yy][zz])<=p){
			vis[xx][yy][zz]=1;
			dfs(xx,yy,zz); 
		} 
	} 
} 
void solve(){
	cin>>n>>m>>h;
	cin>>p;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=1;k<=h;k++) cin>>a[i][j][k];
	for(int i=1;i<=n;i++){
		 for(int j=1;j<=m;j++){
			for(int k=1;k<=h;k++){
		 		if(!vis[i][j][k]){
		 			cnt++; 
		 			vis[i][j][k]=1;
					dfs(i,j,k); 
				} 
			} 
		} 
	} 
	cout<<cnt; 
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


