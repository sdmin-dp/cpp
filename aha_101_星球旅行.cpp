#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
ll a[N][N],dis[N][N];
ll ans=1e12;
void solve(){
	while(cin>>n>>m){
		ans=1e12;
		memset(a,0x3f,sizeof a);
		for(int i=1;i<=m;i++){
			ll u,v,w;
			cin>>u>>v>>w;
			a[u][v]=min(a[u][v],w);
			a[v][u]=min(a[v][u],w);
		}
		memset(dis,0x3f,sizeof(dis));
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					ans=min(ans,dis[i][j]+a[j][k]+a[k][i]);
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		if(ans!=1e12) cout<<ans<<el;
		else cout<<"No solution.\n";
	}
	
}
int main(){
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
