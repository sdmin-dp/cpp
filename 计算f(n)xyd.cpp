#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+10;
ll n,ans,x; 
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		x=i*i+2;
		ans+=x;
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

