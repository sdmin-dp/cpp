#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e4+5;
ll n,m;
struct edge{
	int to;
	int next;
}e[N];
ll h[N];
ll cnt;
bool book[N];
bitset<N> go[N];
void dfs(int idx){
	if(book[idx]) return;
	book[idx]=1;
	for(int i=h[idx];i;i=e[i].next){
		int to=e[i].to;
		dfs(to);
		go[idx]|=go[to];
	}
}
void add(int u,int v){
	++cnt;
	e[cnt].to=v;
	e[cnt].next=h[u];
	h[u]=cnt; 
}
void solve(){
    cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		add(u,v);
	} 
	for(int i=1;i<=n;i++)
		go[i][i]=1;
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	for(int i=1;i<=n;i++){
		cout<<go[i].count()<<'\n';
	} 
}
int main(){
	//ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
	return 0;
} 