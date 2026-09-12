#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e2+5;
ll n,m,ans;
ll a[N][N];
void solve()
{
	//cin
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	//жївЊДњТы
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			if(a[i][j]*a[i+1][j+1]==a[i][j+1]*a[i+1][j])
			{
				ans++;
			}
		}
	}
	//cout
	cout<<ans;
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

