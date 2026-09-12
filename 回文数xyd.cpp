#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
stack<ll> s,p;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x=i;
		while(x>0)
		{
			s.push(x%10);
			x/=10;
		}
		ll y=0;
		x=0;
		while(!s.empty())
		{
			x=s.top();
			p.push(x);
			s.pop();
		}
		while(!p.empty())
		{
			x=p.top();
			y=y*10+x;
			p.pop();
		}
		if(y==i) cout<<i<<el;
	}
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

