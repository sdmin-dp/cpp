#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll l,r;
bool isprime(ll x){
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void solve(){
	cin>>l>>r;
	ll cnt=0;
	for(int i=l;i<=r;i++){
		if(isprime(i)){
			cnt++;
		}
	}
	cout<<cnt;
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
