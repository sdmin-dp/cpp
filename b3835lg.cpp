#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,y;
void solve()
{
	cin>>n>>y;
	if(y==1||y==3||y==5||y==7||y==8||y==10||y==12) cout<<31;
	else if(y==4||y==6||y==9||y==11) cout<<30;
	else if(y==2&&((n%4==0&&n%100!=0)||(n%400==0))) cout<<29;
	else cout<<28;
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

