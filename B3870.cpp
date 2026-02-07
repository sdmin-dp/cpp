#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
string s="0123456789ABCDEF";
void solve(){
	cin>>n;
	do{
		ll k=n%128;
		n/=128;
		if(n!=0){
			k+=128;
		}
		cout<<s[k/16]<<s[k%16]<<" ";
	}while(n);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("xxx.in","r",stdin);
	//freopen("xxx.out","w",stdout);
	ll T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}