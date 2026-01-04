#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e1+5;
ll a,b,c;
ll f[N][N][N];
ll w(ll x,ll y,ll z){
	if(x<=0||y<=0||z<=0) return 1;
	if(x>20||y>20||z>20) return w(20,20,20); 
	if(f[x][y][z]>0) return f[x][y][z];
	if(x<y&&y<z) f[x][y][z]=w(x,y,z-1)+w(x,y-1,z-1)-w(x,y-1,z);
	else f[x][y][z]=w(x-1,y,z)+w(x-1,y-1,z)+w(x-1,y,z-1)-w(x-1,y-1,z-1);
	return f[x][y][z];
}
void solve(){
	while(cin>>a>>b>>c){
		if(a==-1&&b==-1&&c==-1) break;
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
