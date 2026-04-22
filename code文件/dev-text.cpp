#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	return x.first*y.second<y.first*x.second;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1,cmp);
	ll time=0,sum=0;
	for(int i=1;i<=n;i++){
		time+=a[i].first;
		sum+=time*a[i].second;
	}
	cout<<sum;
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

