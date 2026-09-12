#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
ll n,m,q;
ll a[N];
//ll rf(ll x){
//	ll l=1,r=n,mid=0,ans=0;
//	while(l<=r){
//		mid=(l+r)/2;
//		if(a[mid]>=x){
//			ans=mid;
//			r=mid-1;
//		}
//		else{
//			l=mid+1;
//		}
//	}
//	return ans;
//}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(cin>>q){
//		cout<<rf(q)<<" ";
		cout<<upper_bound(a+1,a+n+1,q)-lower_bound(a+1,a+n+1,q)<<" ";
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
	while(T--) solve();
	return 0;
}

