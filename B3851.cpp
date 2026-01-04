#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e1+5;
struct node{
	ll x,q;
	string name="00";
};
node b[300];
map<char,ll> mp;
ll n,m;  
ll x,y;
string s;
ll a[N][N];
ll mx[10];
string w={"0123456789ABCDEF"};
bool cmp(node a,node b){
	if(a.q!=b.q) return a.q>b.q;
	else return a.x<b.x;
}
void solve()
{
	mp.insert({'0',0});mp.insert({'1',1});mp.insert({'2',2});mp.insert({'3',3});mp.insert({'4',4});mp.insert({'5',5});mp.insert({'6',6});mp.insert({'7',7});mp.insert({'8',8});mp.insert({'9',9});mp.insert({'A',10});mp.insert({'B',11});mp.insert({'C',12});mp.insert({'D',13});mp.insert({'E',14});mp.insert({'F',15});
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		m=int(s.size()/2);
		for(int j=0;j<s.size()/2;j++){
			x=mp[s[j*2]],y=mp[s[j*2+1]];
			a[i][j]=x*16+y;
			b[a[i][j]].q++;
			b[a[i][j]].x=a[i][j];
			b[a[i][j]].name[0]=s[j*2];
			b[a[i][j]].name[1]=s[j*2+1];
		}
	}
	sort(b,b+290,cmp);
	for(int i=0;i<16;i++){
		cout<<b[i].name;
	}
	cout<<el;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			ll mn=LONG_LONG_MAX;
			ll p=0;
			for(int k=0;k<16;k++){
				if(abs(a[i][j]-b[k].x)<mn){
					mn=abs(a[i][j]-b[k].x);
					p=k;
				}
			}
			cout<<w[p];
		}
		cout<<el;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

