#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e1+5;
ll n;
bool vis1[N],vis2[N],vis3[N],vis4[N];
bool a[N][N];
ll cnt=0;
void dfs(ll x){
	if(x==n+1){
		cnt++;
		if(cnt<=3){
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][j]) cout<<j<<" ";
			cout<<el;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis1[n+x-i]&&!vis2[x+i]&&!vis3[x]&&!vis4[i]){
			vis1[n+x-i]=vis2[x+i]=vis3[x]=vis4[i]=1;
			a[x][i]=1;
			dfs(x+1);
			vis1[n+x-i]=vis2[x+i]=vis3[x]=vis4[i]=0;
			a[x][i]=0;
		}
	}
}
void solve(){
	cin>>n;
	dfs(1);
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
