#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
void solve(){
	cin>>n;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]%2==0&&cnt!=0){
			a[i]++;
			cnt--;
		}
		if(cnt==0) break;
	}
	ll sum=1;
	for(int i=1;i<=n;i++){
		sum=sum*a[i]%1000000007;
	}
	cout<<sum;
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
