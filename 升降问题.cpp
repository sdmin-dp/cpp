#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e2+5; 
struct node{ll x,step;};
ll q;
ll n,b,e;
ll a[N][2];
void bfs(ll n,ll b,ll e){
	vector<bool> vis(n+1,0); 
	queue<node> q;
	q.push({b,0});
	vis[b]=1;
	while(!q.empty()){
		ll tx=q.front().x;
		ll stp=q.front().step;
		q.pop();
		cout<<tx<<el; 
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
	while(1){
		cin>>n;
		if(n==0) return; 
		cin>>b>>e;
		for(int i=1;i<=n;i++){
			cin>>q;
			if(i+q>n) a[i][0]=i;
			else a[i][0]=i+q;
			if(i-q<1) a[i][1]=i;
			else a[i][1]=i-q;
		}
		bfs(n,b,e); 
		cout<<el; 
	} 
	
	
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
