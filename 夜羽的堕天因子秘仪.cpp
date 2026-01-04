#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll p=1000000007;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b%2==1) res=res*a%p;
		b/=2;
		a=a*a%p;
	}
	return res;
}
void solve(){
	ll n,k;
	cin>>n>>k;
	unsigned long long sum=0;
	for(int i=1;i<=n;i++){
		unsigned long long kk=qpow(i,k);
		sum=(sum+(n/i)*kk%p)%p;
	}
	cout<<sum<<el;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("yoshiko.in","r",stdin);
	freopen("yoshiko.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
