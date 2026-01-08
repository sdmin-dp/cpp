#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=200+5;
ll n;
ll a[N];
ll l,r;
ll b,c;
ll sum;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cin>>l>>r;
    if(sum>n*r||sum<n*l){
        cout<<-1;
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i]<l) b+=l-a[i];
        if(a[i]>r) c+=a[i]-r;
    }
    cout<<max(b,c);
}
int main()
{
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

