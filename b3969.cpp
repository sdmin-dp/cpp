#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
bool vis[N];
ll a[N];
ll n,m;
void init(){
	vis[0]=vis[1]=1;
	for(ll i=2;i<=n;i++){
		if(vis[i]) continue;
		a[i]=i;
		for(ll j=2;i*j<=n;j++){
			vis[i*j]=1;
			a[i*j]=max(a[i*j],i);
		}
	}
}
void solve(){
	cin>>n>>m;
	init();
	ll cnt=0;
	for(int i=1;i<=n;i++) if(a[i]<=m) cnt++;
	cout<<cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r",stdin);
//  freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
