#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e1+5;
ll n,m;
pair<ll,ll> mp[N];
bool flag;
void dfs(ll x,ll step){
	if(x>n+1||step>m) return;
	if(step==m&&flag==0){
		cout<<"yes"<<el;
		flag=1;
		return;
	}
	for(int i=0;i<=mp[x].second;i++){
		ll stp=step+i*mp[x].first; 
		dfs(x+1,stp);
	}
}
void solve(){
	while(1){
		cin>>n;
		if(n==0) return;
		cin>>m;
		flag=0;
		for(int i=1;i<=n;i++) cin>>mp[i].first>>mp[i].second;
		dfs(1,0);
		if(flag==0) cout<<"no"<<el;
	}
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

