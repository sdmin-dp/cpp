#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e3+5;
ll n,m,q;
ll a[N][N],b[N][N],d[N][N];
void solve()
{
	cin>>n>>m>>q;
	ll lx,ly,rx,ry;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=q;i++){
		cin>>lx>>ly>>rx>>ry;
		d[lx][ly]++;
		d[lx][ry+1]--;
		d[rx+1][ly]--;
		d[rx+1][ry+1]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+d[i][j];
			if(b[i][j]%2==1){
				if(a[i][j]==0) a[i][j]=1;
				else a[i][j]=0;
			} 
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

