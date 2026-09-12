#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m;
ll a[N];
pair<ll,ll> b[N];
priority_queue<pair<ll,ll>> q;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.second!=y.second) return x.second>y.second;
    else return x.first>y.first;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i].second;
    for(int i=1;i<=m;i++) cin>>b[i].first;
    sort(a+1,a+n+1,greater<ll>());
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<=m;i++) q.push(b[i]);
    for(int i=1;i<=n;i++){
        while(q.top().second>a[i]){
            
        }
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