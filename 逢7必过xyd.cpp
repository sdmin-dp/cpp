#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
void solve()
{
	for(int i=10;i<=99;i++)
	{
		if(i%10==7||i/10%10==7||i%7==0) cout<<"pass! ";
		else cout<<i<<" ";
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

