#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
ll lx,ly,rx,ry;
char a[N][N];
void solve(){
	cin>>n>>m;
	cin>>lx>>rx>>ly>>ry;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=lx;i<=rx;i++){
		for(int j=ly;j<=ry;j++){
			cout<<a[i][j];
		}
		cout<<el;
	}
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

