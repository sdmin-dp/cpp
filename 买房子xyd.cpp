#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e9+5;
ll n,m,cnt;
void solve()
{
	cin>>n>>m;
	if(m==0)
	{
		cout<<"0 0";
		return;
	}
	for(int i=2;i<=n;i+=3){
		cnt++;
	}
	cout<<"1 ";
	if(cnt<m)
		cout<<n-m; 
	else
		cout<<n-cnt-(cnt-m)*2;
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

