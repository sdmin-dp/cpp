#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n;
ll a[N][N],num[N][N],d[N][N]; 
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			num[i][j]=num[i-1][j]+num[i][j-1]-num[i-1][j-1]+a[i][j];
			d[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
		} 
	}
	ll lx,ly,rx,ry;
	cin>>lx>>ly>>rx>>ry;
	cout<<num[rx][ry]-num[lx-1][ry]-num[rx][ly-1]+num[lx-1][ly-1]<<el;
	ll x;
	cin>>lx>>ly>>rx>>ry>>m;
	d[lx][ly]+=x;
	d[lx][ry+1]-=x;
	d[rx+1][ly]-=x;
	d[rx+1][ry+1]+=x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+d[i][j];
			cout<<a[i][j]<<" ";
		} 
		cout<<el;
	}
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

