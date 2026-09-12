#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e6+5;
ll n,m,k,mm[N],nn[N],ans;
void solve(){
    cin>>n>>m>>k;
	for(int i=1;i<=n;i++) for(int j=i;j<=k;j+=i) ++nn[j];
	for(int i=1;i<=m;i++) for(int j=i;j<=k;j+=i) ++mm[j];
	for(int i=1;i<=k;i++) ans+=i*nn[i]*mm[i];
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
        cout<<el;
    }
    return 0;
}