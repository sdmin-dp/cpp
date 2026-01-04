#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3e3+5;
struct node{
	ll h,w;
};
node a[N];
ll n;
bool cmp(node p,node q){
	if(p.h!=q.h) return p.h>q.h;
	else return p.w>p.w;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].h>>a[i].w;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(cmp(a[j],a[j-1])){
				swap(a[j],a[j-1]);
				cnt++;
			}
		}
	}
//	cout<<el;
//	for(int i=1;i<=n;i++){
//		cout<<a[i].h<<" "<< a[i].w<<el;
//	}
	cout<<cnt;
	
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

