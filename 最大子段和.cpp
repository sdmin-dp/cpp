#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N],num[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[i]=num[i-1]+a[i];
	}
	ll mx=0,mn=1e9;
	for(int i=1;i<=n;i++){
		mx=max(mx,num[i]-mn);
		mn=min(mn,num[i]);
	}
	cout<<mx;
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
