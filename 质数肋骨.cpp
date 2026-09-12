#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
bool isprime(ll x){
	if(x<2) return 0;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void dfs(ll x,ll s){
	if(x==n+1){
		ll t=s;
		while(t>0){
			if(!isprime(t)){
				return;
			}
			t/=10;
		}
		cout<<s<<el;
		return;
	}
	if(x==1){
		dfs(x+1,s*10+2);
		dfs(x+1,s*10+3);
		dfs(x+1,s*10+5);
		dfs(x+1,s*10+7);
	}
	else{
		dfs(x+1,s*10+1);
		dfs(x+1,s*10+3);
		dfs(x+1,s*10+7);
		dfs(x+1,s*10+9);
	}
}
void solve(){
	cin>>n;
	dfs(1,0);
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
