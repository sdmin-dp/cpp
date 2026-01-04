#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n,m;
ll a[N][N],d[N][N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		ll lx,ly,rx,ry;
		cin>>lx>>ly>>rx>>ry;
		d[lx][ly]++;d[lx][ry+1]--;
		d[rx+1][ly]--;d[rx+1][ry+1]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+d[i][j];
			cout<<a[i][j]<<" ";
		}
		cout<<el;
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
	return 0;
}
