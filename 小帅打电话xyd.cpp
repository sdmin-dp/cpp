#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+10;
ll a,b,t,ans; 
void solve()
{
	cin>>a>>b>>t;
	if(a<=b*3)
	{
		ans+=t/a*3;
		t%=a;
		ans+=t/b;
	}
	else
	{
		ans+=3;
		t-=a;
		ans+=t/b;
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

