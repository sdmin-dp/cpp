#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e1+5;
ll n,m,x;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=i;i++)
	{
		bool flag=1;
		x=i;
		for(int j=1;j<=n;j++)
		{
			x-=m;
			if(x%n!=0||x/n==0){
				flag=0;
				break;	
			}
			else x=x/n*(n-1);
		}
		if(flag)
		{
			cout<<i;
			break;
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
