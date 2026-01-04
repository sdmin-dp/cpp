#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
struct node{
	ll begin,end;
	bool operator< (const node b)const {
		return end<b.end;
	}
};
ll n,r;
ll x,y,dis;
node a[N];
void solve()
{
	cin>>n>>r;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(y>r){
			cout<<-1;
			return;
		}
		dis=sqrt(r*r-y*y);
		a[i].begin=x-dis;
		a[i].end=x+dis;
		
	}
	sort(a+1,a+n+1);
	ll cnt=1,last=a[1].end;
	for(int i=2;i<=n;i++){
		if(a[i].begin>last){
			cnt++;
			last=a[i].end; 
		}
	} 
	cout<<cnt;
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

