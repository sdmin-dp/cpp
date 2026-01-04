#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll num[N][N];
ll a[N][N];
ll n,m,c;
void solve()
{
	//cin
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			num[i][j]=num[i-1][j]+num[i][j-1]-num[i-1][j-1]+a[i][j];
		} 
	}
	//жївЊДњТы
	ll mx=-1e9,mxx=0,mxy=0;
	for(int i=1;i<=n-c+1;i++){
		for(int j=1;j<=m-c+1;j++){
			ll xx=i+c-1,yy=j+c-1;
			ll cnt=num[xx][yy]-num[i-1][yy]-num[xx][j-1]+num[i-1][j-1];
//			cout<<cnt<<" ";
			 if(cnt>=mx)
			 {
				mxx=i,mxy=j;
				mx=cnt;
			 }
		}
//		cout<<el;
	}
//	cout<<el;
	//cout
 	cout<<mxx<<" "<<mxy;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<num[i][j]<<" ";
//		}
//		cout<<el;
//	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("xxx.in","r",stdin);
	//freopen("xxx.out","w",stdout);
	ll T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}

