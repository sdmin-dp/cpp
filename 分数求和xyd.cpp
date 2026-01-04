#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+10;
double n,m,k=2;
double ans,x;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		m+=k;
		x=1/m;
		k+=2;
		ans+=x;
	}
	printf("%.2f",ans);
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

