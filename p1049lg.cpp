#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e1+5;
ll n,m;
ll dp[N][20005],v[N];
void solve()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j<v[i])
			{
				dp[i][j]=dp[i-1][j];
			 } 
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]);
			}
		}
	}
	cout<<m-dp[n][m];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}

