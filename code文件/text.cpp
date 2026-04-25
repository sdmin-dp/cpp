#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N][N];
ll id[N];
ll reid[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		id[i]=i;
		reid[i]=i;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	ll q;
	cin>>q;
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll X=reid[x],Y=reid[y];
		swap(id[X],id[Y]);
		reid[id[X]]=X;
		reid[id[Y]]=Y;
	}
	for(int i=1;i<=n;i++){
		ll I=reid[i];
		for(int j=1;j<=m;j++){
			cout<<a[I][j]<<" ";
		}
		cout<<el;
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

