#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n;
ll a[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		ll cnt=0;
		for(int j=1;j<i;j++) if(a[j]<a[i]) cnt++;
		cout<<cnt<<" ";
	}
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

