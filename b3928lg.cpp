#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e4+5;
ll n,win,head=1;
struct node{
	ll x;
	bool vis=1;
};
node a[N];
ll b[N];
bool cmp(node p,node q){
	return p.x<q.x;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x;
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		for(int j=head;j<=n;j++){
			if(a[j].vis&&a[j].x>=b[i]){
				head=j+1;
				a[j].vis=0;
				win++;
				break; 
			}
		}
	}
	cout<<win;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

