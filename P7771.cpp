#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back({y,i});
    }
    ll cnt1=0,cnt2=0,cnt3=0;
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