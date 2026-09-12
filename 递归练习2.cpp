#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
void f(ll x){
	if(x==1){
		cout<<1<<" ";
		return;
	}
	f(x/2);
	cout<<x<<" ";
	f(x-x/2);
}
void solve(){
	cin>>n;
	f(n);
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
