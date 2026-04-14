#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k;
pair<ll,ll> a[N];
pair<ll,ll> cnt[N];

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].second>>a[i].first;
        cnt[a[i].second].first++;
        cnt[a[i].second].second=a[i].second;
    }
    // sort(a+1,a+n+1,cmp);
    sort(cnt+1,cnt+n+1,greater<ll>());
    for(int i=1;i<=n;i++){

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