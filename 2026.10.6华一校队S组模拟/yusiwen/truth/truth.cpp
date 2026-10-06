#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m,k;
ll a[N];
ll vis[35];
void solve(){
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		ll op;
		cin>>op;
		if(op==1){
			ll p,v;
			cin>>p>>v;
			a[p]=v;
		}else{
			ll ans=1e9;
			memset(vis,0,sizeof(vis));
			for(int i=1;i<=n;i++){
				vis[a[i]]=i;
				bool flag=1;
				ll mn=1e9;
				for(int j=1;j<=k;j++){
					if(!vis[j]){
						flag=0;
						mn=1e9;
						break;
					}
					mn=min(mn,vis[j]);
				}
				if(flag) ans=min(ans,i-mn+1);
			}
			if(ans==1e9) cout<<-1<<el;
			else cout<<ans<<el;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}


