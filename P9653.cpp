#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll t,m,n,k;
ll tmp,flag=-10,flag2=-20,ans; 
ll c[N];
void solve(){
    cin>>t;
	for(int i=1;i<=t;i++){
		ans=0,tmp=-10;
		cin>>n>>m>>k;
		for(int j=1;j<=n;j++){
			cin>>c[j];
			if(tmp!=c[j]){
				ans++;
				tmp=c[j];
			}
		}
		for(int j=2;j<n;j++){
			if(m<=0) break;
			if(c[j]==c[j-1]&&c[j]==c[j+1]){
				c[j]=flag;
				ans+=2;
				m--;
			}
		}
		for(int j=1;j<n;j++){
			if(m<=0) break;
			if(c[j]==c[j+1]){
				c[j]=flag2;
				ans++;
				m--;
			}
		}
		cout<<ans<<el;
		for(int j=1;j<=n;j++){
			c[j]=0;
		} 
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

