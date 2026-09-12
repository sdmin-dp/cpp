#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,a;
ll s[310];
ll dp[310][310];
void solve(){
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>a;
		s[i]=s[i-1]+a;
	}
	for(ll len=2;len<=n;++len){
		for(ll l=1;l+len-1<=n;++l){
			ll r=l+len-1;
			dp[l][r]=0x3f3f3f;
			for(ll k=l;k<r;++k){
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+s[r]-s[l-1]);
			}
		}
	}
	cout<<dp[1][n];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}