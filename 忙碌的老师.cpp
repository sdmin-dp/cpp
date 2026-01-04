#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
struct node{
	ll begin,end;
	bool operator< (const node b)const {
		return begin<b.begin;
	}
};
ll n;
node a[N];
priority_queue<ll,vector<ll>,greater<ll> > q;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].begin>>a[i].end;
	sort(a+1,a+n+1);
	ll mx=1;
	q.push(a[1].end);
	for(int i=2;i<=n;i++){
//		cout<<"you are a dog"<<el;
//		cout<<q.top()<<el;
		while(!q.empty()&&q.top()<a[i].begin){
			q.pop();
		}
		q.push(a[i].end);
		mx=max(int(q.size()),int(mx));
	}
	cout<<mx;
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

