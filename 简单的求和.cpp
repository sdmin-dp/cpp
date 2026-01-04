#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m,x;
unordered_map<ll,ll> mp;
void solve()
{
	cin>>n>>m;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		cnt+=mp[m-x];
		mp[x]++;
	}
	cout<<cnt;
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

