#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll yinshu(ll x){
	ll ans=0;
	for(int i=1;i<=x;i++)
	{
		if(x%i==0)
		{
			ans++;
			x/=i;
		}
	}
	return ans;
} 
void solve()
{
	//cin
	cin>>n;
	//жївЊДњТы
	ll cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(yinshu(i)<4)
		{
			cnt++;
		}
	}
	//cout
	cout<<cnt;
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

