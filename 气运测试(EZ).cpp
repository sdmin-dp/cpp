#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
struct node{
	ll val,step;
};
ll n,b,e;
ll a[N][4];
ll stp[N];
bool vis[N];
void bfs(){
	queue<node> q;
	q.push({b,0});
	while(!q.empty()){
		ll x=q.front().val;
		ll stp=q.front().step;
		q.pop();
		if(x==e){
			cout<<stp;
			return;
		}
		for(int i=0;i<4;i++){
			ll xx=a[x][i];
			if(!vis[xx]){
				q.push({xx,stp+1});
				vis[xx]=1;
			}
		}
	}
	cout<<"NO";
}
void solve(){
	cin>>n>>b>>e;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
	bfs();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
