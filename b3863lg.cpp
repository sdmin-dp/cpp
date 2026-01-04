#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll x,y,z,n,m;
void solve()
{
	cin>>x>>y>>z>>n;
	m=x*2+y*5+z*3;
	if(n>=m) cout<<"Yes"<<el<<n-m;
	else cout<<"No"<<el<<m-n; 
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

