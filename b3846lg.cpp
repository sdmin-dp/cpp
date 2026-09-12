#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll l,r,ans;
void solve() 
{
	cin>>l>>r;
	for(int i=l+1;i<r;i++)
	{
		if((i%4==0&&i%100!=0)||(i%400==0))
			ans+=i;
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

