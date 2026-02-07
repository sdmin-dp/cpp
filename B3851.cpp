#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n,m;
string s[N];
ll a[N][N];
ll ans[N][N];
pair<ll,ll> sum[257];
map<char,ll> mp;
map<ll,char> mp2;
ll stoten(string s){
	return mp[s[0]]*16+mp[s[1]];
}
string t;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	if(x.first!=y.first) return x.first>y.first;
	else return x.second<y.second;
}
void solve(){
	for(int i=0;i<=255;i++) sum[i].second=i;
	
	cin>>n;
	for(int i=0;i<=9;i++){
		mp2.insert({i,char(i+48)});
		mp.insert({char(i+48),i});
	}
	for(int i=10;i<=35;i++){
		mp2.insert({i,char(i-10+'A')});
		mp.insert({char(i-10+'A'),i});
	}
	for(int i=1;i<=n;i++) cin>>s[i];
	
	for(int i=1;i<=n;i++){
		ll cnt=0;
		for(int j=0;j<s[i].size();j+=2){
			t=char(s[i][j]);
			t+=char(s[i][j+1]);
			a[i][++cnt]=stoten(t);
			sum[a[i][cnt]].first++;
		}
		m=cnt;
	}
	sort(sum,sum+256,cmp);
	for(int i=0;i<=15;i++){
		ll u=sum[i].second;
		// cout<<u<<" ";
		t="";
		for(int i=1;i<=2;i++){
			ll k=u%16;
			t+=mp2[k];
			// cout<<mp2[k]<<el;
			u/=16;
		}
		cout<<t[1]<<t[0];
	}
	cout<<el;
	for(int i=1;i<=n;i++){	
		for(int j=1;j<=m;j++){
			ll id=0,mn=1e9;//id记录灰阶值，mn记录最小差值
			for(int k=0;k<=15;k++){
				//abs(a[i][j]-sum[i].second)
				if(abs(a[i][j]-sum[k].second)<mn){
					id=k;
					mn=abs(a[i][j]-sum[k].second);
				}
			}
			ans[i][j]=id;
			// cerr<<ans[i][j]<<" ";
		}
		// cerr<<el;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<mp2[ans[i][j]];
		}
		cout<<el;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("xxx.in","r",stdin);
	//freopen("xxx.out","w",stdout);
	ll T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}