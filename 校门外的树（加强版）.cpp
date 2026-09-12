#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N],d[N];
void solve()
{
	ll n,m;
	cin>>n>>m;
	ll l,r;
	for(int i=1;i<=m;i++){
		cin>>l>>r;
		d[l]++;
		d[r+1]--;
	}
	ll cnt=0;
	for(int i=0;i<=n;i++){
		a[i]=a[i-1]+d[i];
		if(a[i]==0){
			cnt++;
		}
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

