#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
ll n,x=1,ans;
ll a[N];
bool rf(ll t){
	ll l=x,r=n,mid,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]>=t){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	x=ans+1;
	if(ans==0||ans>n) return 0;
	else return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll day=1,x=1;
	while(1){
		if(rf(day)){
			day++;
		}
		else{
			cout<<day-1;
			return;
		}
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

