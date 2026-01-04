#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
constexpr ll N=1505;
ll n=0,m,maxn=LONG_LONG_MIN,cnt,k[2250005],dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
char c[N][N];
bool vis[N][N];
void dfs(ll x,ll y,ll z){
	for(ll i=0;i<8;i++){
		ll xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&c[xx][yy]=='*'&&vis[xx][yy]==0){
			vis[xx][yy]=1;
			cnt++;
			dfs(xx,yy,z+1);
		}
	}
}
void solve(){
	ll sum=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cnt=0;
			if(vis[i][j]==0&&c[i][j]=='*'){
				vis[i][j]=1;
				cnt++;
				dfs(i,j,1);
			}
			k[cnt]++;
		}
	}
	for(ll i=1;i<=n*m;i++){
		if(k[i]>0) sum++;
		maxn=max(maxn,k[i]*i);
	}
	cout<<sum<<" "<<maxn;
}
int main(){
	//freopen("xxx.in","r",stdin);
	//freopen("xxx.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
