#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1);
    ll t=-1e12,cnt=1;
    for(int i=1;i<=n-1;i++){
        if(a[i].first-a[i].second>t) cnt++,t=a[i].first;
        else if(a[i].first+a[i].second<a[i+1].first) cnt++,t=a[i].first+a[i].second;
        else t=a[i].first;
    }    
    cout<<cnt;
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