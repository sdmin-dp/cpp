#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
ll num;
bool vis[N];
void solve(){
	cin>>n>>m;
	num=n;
	ll cnt=0;
	while(num>0){
		for(int i=1;i<=n;i++){
			if(!vis[i]) cnt++;
			if(cnt==m){
				vis[i]=1;
				cnt=0;
				num--;
				cout<<i<<" ";
			}
		}
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

