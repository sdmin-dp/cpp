#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
ll a[5][5];
ll ans=1e9;
ll p=0;
ll check(){
	bool flag=1;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(a[i][j]==0){
				return 0;
			}
		}
	}
	return 1;
}
void dfs(int x){
	if(x==10){
		if(check()==1){
			ans=min(ans,p);
		}
		return;
	}
    ll xx,yy;
	xx=(x-1)/3+1;
	yy=x%3;
	if(yy==0){
		yy=3;
	}
    a[xx+1][yy]=a[xx+1][yy]^1;
    a[xx-1][yy]=a[xx-1][yy]^1;
    a[xx][yy]=a[xx][yy]^1;
    a[xx][yy+1]=a[xx][yy+1]^1;
    a[xx][yy-1]=a[xx][yy-1]^1;
	p++;
	dfs(x+1);
    a[xx+1][yy]=a[xx+1][yy]^1;
    a[xx-1][yy]=a[xx-1][yy]^1;
    a[xx][yy]=a[xx][yy]^1;
    a[xx][yy+1]=a[xx][yy+1]^1;
    a[xx][yy-1]=a[xx][yy-1]^1;
    p--;
	dfs(x+1);
}
int main(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	dfs(1);
	cout<<ans;
}
