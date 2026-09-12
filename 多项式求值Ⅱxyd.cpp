#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
double ans,cnt;
ll n,m=1;
bool flag;
void solve()
{
	cin>>n;
	while(1)
	{
		flag=1;
		for(int i=1;i<=m;i+=2)
		{
			if(!flag){
				cnt-=i;
				flag=1;
			}
			else{
				cnt+=i;
				flag=0;
			}
		}
		ans+=1/cnt;
		m+=2;
		if(m>=2*n-1) break; 
	}
	printf("%.3f",ans);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("xxx.in","r",stdin);
	//freopen("xxx.out","w",stdout);
	ll T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}

