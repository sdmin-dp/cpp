#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+10;
ll n,a,b,x,y,ans;
void solve()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		x=i-1,y=n-i;
		if(!(x<a)&&!(y>b))
		{
			ans++;
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

