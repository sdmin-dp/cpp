#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll s1[N],s2[N],dp[N][N];
ll n,ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s1[i];
	for(int i=1;i<=n;i++) cin>>s2[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
			if(s1[i]!=s2[j]) dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans;
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

