#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string a={"0123456789ABCDEF"};
ll n;
void solve()
{
	cin>>n;
	ll m=pow(2,7);
	if(n==0){
		cout<<"00";
		return;
	}
	while(n>0){
		ll k=n%m;
		n/=m;
		if(n>0) k+=m;
		cout<<a[k/16]<<a[k%16]<<" ";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

