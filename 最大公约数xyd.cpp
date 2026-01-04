#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
void solve()
{
	cin>>n>>m;
	while(max(n,m)-min(n,m)!=min(n,m))
	{
		ll x=n,y=m;
		m=max(x,y)-min(x,y);
		n=min(x,y);
	}
	cout<<min(n,m);
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

