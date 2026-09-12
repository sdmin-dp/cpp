#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,q;
ll a[N];
map<ll,vector<ll>> cnt;
void solve(){
    cnt.clear();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]].push_back(i);
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        ll l,r,x;
        cin>>l>>r>>x;
        ll t=upper_bound(cnt[x].begin(),cnt[x].end(),r)-lower_bound(cnt[x].begin(),cnt[x].end(),l);
        cout<<t<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}