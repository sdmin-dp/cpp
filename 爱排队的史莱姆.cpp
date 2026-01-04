#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll x;
queue<ll> qq;
priority_queue<ll> q;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		qq.push(x);
	}
	while(q.size()+qq.size()>=m){
		while(q.size()<m){
			q.push(qq.front());
			qq.pop();
		}
		cout<<q.top()<<" ";
		q.pop();
	}
	cout<<qq.front();
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

