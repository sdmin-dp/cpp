#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,cnt=1,ans;
void solve()
{
	//cin
	cin>>n;
	//жївЊДњТы
	for(int i=1;i<=n;i++)
	{
		cnt*=i;
		ans+=cnt;
	}
	//cout
	cout<<ans;
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

