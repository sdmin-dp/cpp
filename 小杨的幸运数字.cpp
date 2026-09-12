#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n; 
void fjzys(ll n){
	set<ll> s; 
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0){
				s.insert(i);
				n/=i; 
			} 
		}
	} 
	if(n>1) s.insert(n); 
	if(s.size()==2) cout<<1<<el;
	else cout<<0<<el; 
} 
void solve(){
	cin>>n; 
	fjzys(n); 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1; 
	cin>>T;
	while(T--){
		solve();
	}
} 


