#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll vis[N];
vector<ll> pri;
void init(){
	vis[0]=vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]) pri.push_back(i);
		for(auto j:pri){
			if(j*i>n) break;
			vis[i*j]=1;
			if(i%j==0) break;
		}
	}
}
void solve(){
	cin>>n;
	init();
	for(auto i:pri) cout<<i<<" ";
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
