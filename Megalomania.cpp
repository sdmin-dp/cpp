#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
pair<ll,ll> a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].second>>a[i].first;
    sort(a+1,a+n+1);
    ll time=0;
    for(int i=1;i<=n;i++){
        if(time+a[i].second<=a[i].first) time+=a[i].second;
        else{cout<<"No";return;}
    }
    cout<<"Yes";
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