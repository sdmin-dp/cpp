#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e1+5;
ll n;
ll a[N];
void solve()
{
	cin>>n;
	a[1]=1;
	a[2]=1;
	cout<<a[1]<<" "<<a[2]<<" "; 
	for(int i=3;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
		cout<<a[i]<<" ";
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

