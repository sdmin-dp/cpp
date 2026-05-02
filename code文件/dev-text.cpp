#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
<<<<<<< HEAD
ll n;
map<ll,string> mp;
bool isnum(char c){
	return (c>='0'&&c<='9');
=======
const ll mxlog=17;
ll n,m;
ll a[N];
ll st[N][20];
ll lg2[N];
void init(){
    for(int i=1;i<=n;i++) st[i][0]=a[i];
    for(int j=1;j<=mxlog;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]); 
        }
    }
    for(int i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
}
ll query(ll l,ll r){
    ll k=lg2[r-l+1];
    return max(st[l][k],st[r-(1<<k)+1][k]);
>>>>>>> f422e9f9310ed6966c1d231f260a30b1f3a9c3d9
}
vector<pair<ll,ll>> v;
void solve(){
<<<<<<< HEAD
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;string t;
		cin>>x;
		cin>>t;
		mp[x]=t;
	}
	string s,t;
	cin>>s;
	getline(cin,t);
	s=s+t;
	for(int i=0;i<s.size();i++){
		if(s[i]=='#'){
			ll x=0;
			i++;
			ll len=0;
			while(i<s.size()&&isnum(s[i])){
				x=x*10+int(s[i]-48);
				i++;
			}
			i--;
			v.push_back({x,i});
		}
	}
	ll cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='#'){
			cout<<mp[v[cnt].first];
			i=v[cnt].second;
			cnt++;
		}else{
			cout<<s[i];
		}
	}
=======
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        cout<<query(x,y)<<el;
    }
>>>>>>> f422e9f9310ed6966c1d231f260a30b1f3a9c3d9
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
