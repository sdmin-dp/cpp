#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
double n,cnt;
void solve()
{
	cin>>n;
	if(n<=10) cnt=n*0.1;
	else if(n>10&&n<=20) cnt=10*0.1+(n-10)*0.075;
	else if(n>20&&n<=40) cnt=10*0.1+10*0.075+(n-10-10)*0.05;
	else if(n>40&&n<=60) cnt=10*0.1+10*0.075+20*0.05+(n-10-10-20)*0.03;
	else if(n>60&&n<=100) cnt=10*0.1+10*0.075+20*0.05+20*0.03+(n-10-10-20-20)*0.015;
	else cnt=10*0.1+10*0.075+20*0.05+20*0.03+40*0.015+(n-40-20-20-10-10)*0.01;
	printf("%.2f",cnt);
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

