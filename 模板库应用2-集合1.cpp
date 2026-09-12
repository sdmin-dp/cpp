#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e1;
set<ll> s[N];
ll op; 
ll x,y; 
void solve()
{
	ll n;
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			cin>>x>>y;
			s[x].insert(y); 
		}
		else if(op==2){
			cin>>x>>y;
			s[x].erase(y);
		}
		else if(op==3){
			cin>>x>>y;
			set<ll> a;
			a=s[x];
			for(auto j=s[y].begin();j!=s[y].end();j++){
				a.insert(*j);
			}
			s[x]=a;
			s[y].clear();
		}
		else if(op==4){
			cin>>x>>y;
			set<ll> a;
			for(auto j=s[y].begin();j!=s[y].end();j++){
				if(s[x].find(*j)!=s[x].end()){
					a.insert(*j);
				}
			}
			s[x]=a;
			s[y].clear();
		}
		else if(op==5){
			cin>>x>>y;
			if(s[x].find(y)==s[x].end()){
				cout<<"No"<<el; 
			}
			else{
				cout<<"Yes"<<el;
			}
		}
		else if(op==6){
			cin>>x;
			cout<<s[x].size()<<el;
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

