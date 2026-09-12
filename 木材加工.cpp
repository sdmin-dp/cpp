#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N];
bool check(ll x){
	ll cnt=0;
	for(int i=1;i<=n;i++) cnt+=a[i]/x;
	return cnt>=m;
}
ll rf(){
	ll l=1,r=1e9,mid=0,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1; 
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<rf();
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

