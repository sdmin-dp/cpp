#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m,ans;
bool check(ll x)
{
	ll num=x*n+m;
	for(int i=1;i<n;i++)
	{
		if(num%(n-1)!=0) return 0;
		else num=num/(n-1)*n+m;
	}
	ans=num;
	return 1;
 } 
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=i;i++)
	{
		if(check(i))
		{
			cout<<ans;
			return;
		}
	}
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

