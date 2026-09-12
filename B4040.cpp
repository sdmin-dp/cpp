#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
char a[N][N];
bool check(int x,int y){
	for(int i=x;i<=x+3;i++){
		for(int j=y;j<=y+3;j++){
			if(i==x||i==x+3){
				if(a[i][j]!='0'){
					return 0;
				}
			}
			else{
				if(j==y||j==y+3){
					if(a[i][j]!='0'){
						return 0;
					} 
				}
				else{
					if(a[i][j]!='1'){
						return 0;
					}
				}
			}
		}
	}
	return 1;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(check(i,j)){
				cout<<"Yes"<<el;
				return;
			}
		}
	}
	cout<<"No"<<el;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("xxx.in","r",stdin);
	//freopen("xxx.out","w",stdout);
	ll T=1;
	cin>>T; 
	while(T--)
	{
		solve();
	}
	return 0;
}

