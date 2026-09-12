#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,l,r,ans;
void solve()
{
	cin>>n>>l>>r;
	for(int i=l;i<=r;i++) if(i%n==0||i%10==n) ans+=i;
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

