#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=10+5;
ll n,k;
ll a[N];
ll sum;
void dfs(ll x){
	if(n==0) return;
	if(x==k){
		if(n>=a[x-1]) sum++;
		return;
	}
	for(ll i=a[x-1];i<=n/(k-x+1);i++){
		a[x]=i;
		n-=i;
		dfs(x+1);
		n+=i;
	}
}
void solve(){
    cin>>n>>k;
    a[0]=1;
    dfs(1);
    cout<<sum;
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