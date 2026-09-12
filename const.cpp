#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
ll n,b,m;
ll a[N],pri[N];
bool vis[N];
void init(){
	for(int i=2;i<=b;i++){
		if(!vis[i]) pri[m++]=i;
		for(int j=1;j<=m;j++){
			 if(i*pri[j]>b) break;
			 vis[pri[j]*i]=1;
			 if (i%pri[j]==0) break;
		}
	}
}
void solve(){
	cin>>n>>b;
	init();
	ll cnt=1;
	cout<<m;
//	for(int i=1;i<=m;i++){
//		cnt+=pri[i]-1;
//		for(int j=pri[i];j<=n;j*=pri[i]) cnt++;
//	}
//	cout<<cnt;
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

