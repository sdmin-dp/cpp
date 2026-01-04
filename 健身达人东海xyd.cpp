#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e1+5;
ll day,n,ans;
ll km[N]={0,250,250,250,250,250,0,0};
void solve()
{
	cin>>day>>n;
	ans+=km[day];
	for(int i=2;i<=n;i++)
	{
		day++;
		if(day%7==0) day=7;
		else day%=7;
		ans+=km[day];
	}
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

