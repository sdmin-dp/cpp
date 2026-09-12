#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
double n,ans;
void solve()
{
	cin>>n;
	ans+=n; 
	for(int i=1;i<=10;i++)
	{
		n/=2;
		ans+=n*2;
	}
	ans-=n*2;
	cout<<ans<<el<<n;
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

