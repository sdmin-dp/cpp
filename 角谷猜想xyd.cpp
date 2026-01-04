#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
void solve()
{
	cin>>n;
	while(n!=1)
	{
		if(n%2==1){
			printf("%lld*3+1=%lld\n",n,n*3+1);
			n=n*3+1;
		}
		else if(n%2==0){
			printf("%lld/2=%lld\n",n,n/2);
			n/=2;
		} 
	}
	cout<<"End"<<el;
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

