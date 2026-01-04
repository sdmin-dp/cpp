#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll a[10][N];
ll size[10];
ll n,m;
ll cnt;
void dfs(ll x,ll step){
	if(step<=m&&x>n) return;
	if(step>m){
		ll cj=1;
		for(int i=x+1;i<=n;i++) cj*=(size[i]+1);
		cnt+=cj;
		return;
	}
	x++;
	for(int i=0;i<=size[x];i++){
		dfs(x,step+a[x][i]);
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>size[i];
		for(int j=1;j<=size[i];j++){
			cin>>a[i][j];
		}
	}
	dfs(0,0);
	cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//  freopen("xxx.in","r".stdin);
//  freopen("xxx.out","w".stdout);
    ll T=1;
//  cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

