#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e3+5;
ll n;
ll a[N];
bool check(ll x,ll k){
	for(int i=1;i<x;i++){
		if(a[i]==k){
			return 0;
		}
	}
	return 1;
}
void solve()
{
	cin>>n;
	a[1]=1;
	for(int i=2;i<=n;i++){
		ll k=a[i-1]-i;
		if(k>0&&check(i,k)) a[i]=k;
		else a[i]=a[i-1]+i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
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

