#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll m,b,y,x,ans;
double n;
void solve()
{
	cin>>m>>b;
	for(int i=1;i<=i;i++)
	{
		n=(0-i)/m+b;
		if((0-i)/m+b==n)
		{
			x=i;
			y=((0-i)/m+b);
			break;
		}
	}
	for(int i=0;i<=x;i++)
	{
		for(int j=0;i<=y;j++)
		{
			ans+=i+j;
		}
	}
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

