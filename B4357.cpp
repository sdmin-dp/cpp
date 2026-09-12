#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
ll l,r;
bool a[N];
void solve()
{
	cin>>l>>r;
	for(int i=1;i<=r;i*=2) a[i]=1;
	ll cnt=0;
	for(int i=l;i<=r;i++){
		for(int j=1;j<=i;j*=2){
			if(a[i-j]){
				cnt++;
				break;
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
	while(T--)
	{
		solve();
	}
	return 0;
}

