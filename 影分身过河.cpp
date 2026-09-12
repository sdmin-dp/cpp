#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e3+5;
struct node{
	ll val,step;
};
ll n;
ll a[N];
bool vis[N];
queue<node> q;
void bfs(){
	q.push({1,0});
	while(!q.empty()){
		ll x=q.front().val;
		ll y=q.front().step;
		q.pop();
		if(x==n){
			cout<<y;
			return;
		}
		if(a[x]<=0){
			for(int i=1;i<=x+a[x];i++){
				if(!vis[i]){
					q.push({i,y+1});
					vis[i]=1;
				}
			}
		}
		else{
			for(int i=x+1;i<=x+a[x];i++){
				if(i>n) break;
				if(!vis[i]){
					q.push({i,y+1});
					vis[i]=1;
				}
			}
		}
	}
	cout<<-1;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	vis[1]=1;
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
	return 0;
}

