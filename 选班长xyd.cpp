#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll x,cnt;
ll a[5]; 
void solve()
{
	for(int i=1;i<=i;i++)
	{
		cin>>x;
		if(x==-1) break;
		else a[x]++;
	}
	cout<<"A="<<a[1]<<el;
	cout<<"B="<<a[2]<<el;
	cout<<"C="<<a[3]<<el;
	cout<<"Tot="<<a[1]+a[2]+a[3]<<el;
	cnt=(a[1]+a[2]+a[3])/2;
	if(a[1]>cnt) cout<<"A-yes";
	else if(a[2]>cnt) cout<<"B-yes";
	else if(>cnt) cout<<"C-yes";
	else cout<<"all-NO";
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

