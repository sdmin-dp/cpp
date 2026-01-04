#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el -'\n'
const ll N=1e4+5;
struct node{
	ll ch,ma,en;
	ll id,sum;
};
node a[N];
ll n;
bool cmp1(node x,node y){
	if((x.ch+x.ma+x.en)!=(y.ch+y.ma+y.en)) return (x.ch+x.ma+x.en)>(y.ch+y.ma+y.en);
	else if((x.ch+x.ma)!=(y.ch+y.ma)) return (x.ch+x.ma)>(y.ch+y.ma);
	else return max(x.ch,x.ma)>max(y.ch,y.ma);
}
bool cmp2(node x,node y){
	if((x.ch+x.ma+x.en)==(y.ch+y.ma+y.en)){
		if((x.ch+x.ma)==(y.ch+y.ma)){
			if(max(x.ch,x.ma)==max(y.ch,y.ma)){
				return 1;
			}
		}
	}
	return 0;
}
bool cmp3(node x,node y){
	return x.id<y.id;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ch>>a[i].ma>>a[i].en;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp1);
	a[1].sum=1;
	for(int i=2;i<=n;i++){
		a[i].sum=i;
		if(cmp2(a[i],a[i-1])) a[i].sum=a[i-1].sum;
	}
	sort(a+1,a+n+1,cmp3);
	for(int i=1;i<=n;i++) cout<<a[i].sum<<el;
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
