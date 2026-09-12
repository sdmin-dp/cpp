#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
bool flag=1; 
void fjzys(){
	if(n%2==0){
		ll cnt=0;
		while(n>1&&n%2==0){
			n/=2;
			cnt++; 
		} 
		if(flag){
			flag=0;
			if(cnt==1) cout<<2;
			else cout<<2<<'^'<<cnt; 
		} 
		else{
			if(cnt==1) cout<<" * "<<2;
			else cout<<" * "<<2<<'^'<<cnt; 
		} 
	} 
	for(ll i=3;i*i<=n;i+=2){
		if(n%i==0){
			ll cnt=0; 
			while(n>1&&n%i==0){
				cnt++;
				n/=i; 
			}
			if(flag){
				flag=0; 
				if(cnt==1) cout<<i; 
				else cout<<i<<'^'<<cnt; 
			} 
			else{
				if(cnt==1) cout<<" * "<<i; 
				else cout<<" * "<<i<<'^'<<cnt; 
			} 
		} 
	}
	if(n>1){
		if(flag) cout<<n;
		else cout<<" * "<<n; 
	} 
} 
void solve(){
	cin>>n;
	fjzys(); 
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
}


