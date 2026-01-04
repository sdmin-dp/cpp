#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
map<ll,ll> mp;
ll n,op;
ll x,y;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			cin>>x>>y;
			mp.insert({x,0});
			mp[x]+=y;
		}
		else if(op==2){
			cin>>x;
			if(mp.find(x)==mp.end()){
				cout<<"NO"<<el;
			}
			else{
				cout<<"YES"<<el;
			}
		}
	}
	for(auto i=mp.begin();i!=mp.end();i++){
		cout<<i->first<<" "<<i->second<<el;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

