#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
void solve()
{
	int n;
	cin>>n;
	int x = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x =max(x,a[i]);
	}
	int fl = 0;
	for(int i=1;i<=n;i++)
	{
		if(x%a[i]) fl=1;
	}
	if(fl)cout<<"No\n";
	else cout<<"Yes\n";
}
int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
