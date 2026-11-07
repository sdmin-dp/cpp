#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
char a[N][N];
ll ans=0;
int n,m;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void dfs(ll sx,ll sy){
	stack<pair<int,int> > st;
	st.push(make_pair((int)sx,(int)sy));
	a[sx][sy]='.';
	while(!st.empty()){
		int x=st.top().first,y=st.top().second;
		st.pop();
		for(int i=0;i<4;i++){
			ll xx=x+dx[i],yy=y+dy[i];
			if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&a[xx][yy]=='#'){
				a[xx][yy]='.';
				st.push(make_pair((int)xx,(int)yy));
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            ll cnt0=0,cnt1=0;
            for(int x=i;x<=i+1;x++){
                for(int y=j;y<=j+1;y++){
                    if(a[x][y]=='.') cnt0++;
                    else cnt1++;
                }
            }
            if(cnt0==1&&cnt1==3){
                printf("Bad placement.");
                return;
            }
        }
    }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='#'){
				dfs(i,j);
				ans++;
			}		
		}
	}
    printf("There are %lld ships.",ans);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
