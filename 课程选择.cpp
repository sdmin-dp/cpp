#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
struct node{
	ll begin,end;
}a[N];
ll n;
bool cmp(node x,node y){
	return x.end<y.end;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].begin>>a[i].end;
	sort(a+1,a+n+1,cmp);
	ll lastend=a[1].end,cnt=1;
	for(int i=2;i<=n;i++){
		if(a[i].begin>=lastend){
			lastend=a[i].end;
			cnt++;
		}
	}
	cout<<cnt<<el; 
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

