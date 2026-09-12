#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
void solve()
{
	ll n,x,y;
	queue<ll> a;
	queue<ll> b;
	stack<ll> s;
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>x;
		a.push(x);
	}
	for(int i=1;i<=n;i++){
		cin>>y;
		b.push(y);
	}
	while(!a.empty()&&!b.empty()){
		s.push(a.front());
		a.pop();
		while(!s.empty()&&!b.empty()){
			if(s.top()==b.front()){
				s.pop();
				b.pop();
			} 
			else{
				break;
			}
		}
		
	}
	if(!a.empty()||!b.empty()||!s.empty()){
		cout<<"No"<<el;
	}
	else{
		cout<<"Yes"<<el;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

