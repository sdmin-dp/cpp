#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
bool flag=1;
void fj(ll x){
	bool flag=1;
	for(int i=2;i<=n;i++){
		if(n==0) return;
		if(n%i==0){
			while(n%i==0){
				n/=i;
				if(flag) cout<<i,flag=0;
				else cout<<"*"<<i;
			}
		}
	}
}
void solve(){
	cin>>n;
	cout<<n<<"=";
	fj(2);
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
