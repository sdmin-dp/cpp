#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k;
pair<ll,ll> a[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
unordered_map<ll,ll> mp;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    return x.second<y.second;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        ll p1=a[i].first,p1=a[i].second;
        if(mp.find(PRIBFAST)){

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