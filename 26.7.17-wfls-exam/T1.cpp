#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,m;
vector<ll> t;
void solve(){
    cin>>n>>m;
    ll ans=0,x=0;
    for(int i=1;i<=n;i++){
        ll u,v;
        cin>>u>>v;
        ans+=abs(u-v);
        t.push_back(u);
        t.push_back(v);
    }
    sort(t.begin(),t.end());
    x=t[t.size()/2-1];
    for(auto i:t) ans+=abs(i-x);
    cout<<x<<" "<<ans;
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