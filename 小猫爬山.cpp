#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=18+5;
ll n,m;
ll a[N];
vector<ll> v;
ll ans=1e9;
void dfs(ll x,ll step){
	if(step>=ans) return;
	if(x==n+1){
		ans=min(ans,step);
		return;
	}
	for(int i=0;i<v.size();i++){
		if(v[i]+a[x]<=m){
			v[i]+=a[x];
			dfs(x+1,step);
			v[i]-=a[x];
		}
	}
	v.push_back(a[x]);
	dfs(x+1,step+1);
	v.pop_back();
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans;
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

