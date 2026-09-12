#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n;
ll f[N];
void solve(){
	cin>>n;
	f[1]=1;
	f[2]=2;
	f[3]=4;
	for(int i=4;i<=n;i++){
		f[i]=f[i-3]+f[i-2]+f[i-1];
		f[i]%=998244353;
	}
	cout<<f[n];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r",stdin);
//  freopen("xxx.out","w",stdout);
	ll T=1;
//  cin>>T;
	while(T--){
		solve();
	}
}

