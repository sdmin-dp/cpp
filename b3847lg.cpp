#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll h,m,s;
char c;
void solve()
{
	cin>>h>>m>>s;
	cin>>c;
	if(c=='P') h+=12;
	s+=h*60*60;
	s+=m*60;
	cout<<s;
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

