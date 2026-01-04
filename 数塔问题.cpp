#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n;
ll dx[]={1,1},dy[]={0,1};
ll a[N][N];
ll f[N][N];
ll dfs(ll x,ll y){
	if(f[x][y]>0) return f[x][y];
	for(int i=0;i<2;i++){
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&yy>=1&&xx<=n&&yy<=xx){
			f[x][y]=max(f[x][y],dfs(xx,yy)+a[x][y]);
		}
	}
	return f[x][y];
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
			f[n][j]=a[n][j];
		}
	}
	dfs(1,1);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			cout<<f[i][j]<<" ";
////			f[n][j]=a[n][j];
//		}
//		cout<<el;
//	}
	cout<<f[1][1];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r",stdin);
//  freopen("xxx.out","w",stdout);
	ll T=1;
//  cin>>T;
	while(T--){
		solve();
	}
}

