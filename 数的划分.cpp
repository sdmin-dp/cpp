#include<bits/stdc++.h>                      
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll cnt=0;
void dfs(ll x,ll step,ll last){
	if(x==0){
		if(step==0) cnt++;
		return;
	}
	for(int i=last;i<=step;i++){
		dfs(x-1,step-i,i);
	}
}
void solve(){
	cin>>n>>m;
	dfs(m,n,1);
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
}
