#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll l1,l2,r1,r2;
void solve()
{
	cin>>l1>>l2>>r1>>r2;
	l2+=l1*60;
	r2+=r1*60;
	cout<<r2-l2;
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

