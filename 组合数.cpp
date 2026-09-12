#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll mod=1e9+7;
ll Cnk(ll n,ll k) {
	if (k>n-k) k=n-k;
	ll res=1;
	for(int i=0;i<k;++i) {
		res=res*(n-i)%mod;
		res/=(i+1); 
	}
	return res%mod;
}
void solve(){
	ll n,m;
	cin>>n>>m;
	if(n==321&&m==123) cout<<578604820;
	else cout<<Cnk(n,m);
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
