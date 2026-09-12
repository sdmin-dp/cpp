#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll x,y,n,m; 
void solve()
{
	cin>>x>>y>>n;
	m=x+y;
	if((m%2==0&&n%2==0)||(m%2==1&&n%2==1)) cout<<"Yes";
	else cout<<"No";
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

