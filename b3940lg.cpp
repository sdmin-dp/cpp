#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e1+5;
ll n; 
ll a[N][N];
void solve()
{
	cin>>n;
	ll x=1,y=n/2+1;
	a[1][n/2+1]=1;
	for(int i=2;i<=n*n;i++){
		ll xx=x,yy=y;
		xx--;
		if(xx==0) xx=n;
		yy++;
		if(yy==n+1) yy=1;
		if(a[xx][yy]!=0){
			x++;
			if(x==n+1) x=1;
			a[x][y]=i;
		}
		else{
			x=xx,y=yy;
			a[x][y]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
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
	while(T--)
	{
		solve();
	}
	return 0;
}

