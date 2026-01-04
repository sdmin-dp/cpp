#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e2+5;
struct node{ll x,step;};
ll n,b,e,q;
ll a[N][2];
bool vis[N];
void bfs(){
	queue<node> q;
	q.push({b,0});
	while(!q.empty()){
		ll tx=q.front().x;
		ll stp=q.front().step;
		q.pop();
		if(tx==e){
			cout<<stp;
			return;
		}
		for(int i=0;i<2;i++){
			if(!vis[a[tx][i]]){
				vis[a[tx][i]]=1;
				q.push({a[tx][i],stp+1});
			}
		}
	}
	cout<<-1;
}
void solve(){
	cin>>n>>b>>e;
	for(int i=1;i<=n;i++){
		cin>>q;
		if(i+q>n) a[i][0]=i;
		else a[i][0]=i+q;
		if(i-q<=0) a[i][1]=i;
		else a[i][1]=i-q;
	}
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
