#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N]; 
bool check(ll x){
	ll cnt=0,res=1;
	for(int i=1;i<=n;i++){
		
		cnt+=a[i];
		if(cnt>x){
			cnt=a[i];
			res++;
		}
	}
	if(cnt>x) res++;
	return res<=m;
}
ll rf(){
	ll w=0;
	for(int i=1;i<=n;i++) w+=a[i];
	ll l=1,r=w,mid=0,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		cout<<mid<<" "<<check(mid)<<el;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
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

