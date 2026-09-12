#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
map<string,ll> mp;
ll n,op;
string s;
ll x;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op;
		cin>>s;
		if(op==1){
			cin>>x;
			mp.insert({s,0});
			mp[s]=x;
		}
		else if(op==2){
			if(mp.find(s)==mp.end()){
				cout<<"Not found."<<el;
			}
			else{
				cout<<mp[s]<<el;
			}
		}
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

