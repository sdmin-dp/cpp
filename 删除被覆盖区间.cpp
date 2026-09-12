#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
struct node{
	ll l,r;
};
bool cmp(node x,node y){
	return x.l<y.l;
}
node a[N]; 
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
	ll cnt=n;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j].l<=a[i].l&&a[j].r>=a[i].r){
				cnt--;
			}
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

