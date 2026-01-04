#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e5+5;

void solve()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n+5);
	for(int i=1;i<=n;i++) cin>>a[i];
	ll cnt=a[1],j=1,ans=0;
	for(int i=1;i<=n;i++){
		while(cnt<m&&j<n||j<i){
			j++;
			cnt+=a[j];
		}
		if(cnt==m){
			ans++;
		}
		cnt-=a[i];
	}
	cout<<ans<<el;
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
