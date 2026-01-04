#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e3+5;
ll n,m,q;
ll a[N][N],num[N][N]; 
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			num[i][j]=num[i-1][j]+num[i][j-1]-num[i-1][j-1]+a[i][j];
		} 
	}
	ll lx,ly,rx,ry;
	for(int i=1;i<=q;i++){
		cin>>lx>>ly>>rx>>ry;
		cout<<num[rx][ry]-num[lx-1][ry]-num[rx][ly-1]+num[lx-1][ly-1]<<el;
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

