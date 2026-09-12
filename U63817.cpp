#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n;
pair<ll,ll> a[N];
vector<pair<ll,ll>> x,y;
bool cmp(pair<ll,ll> X,pair<ll,ll> Y){
    return X.second>Y.second;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first;
    for(int i=1;i<=n;i++) cin>>a[i].second;
    for(int i=1;i<=n;i++){
        if(a[i].first<a[i].second) x.push_back(a[i]);
        else y.push_back(a[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end(),cmp);
    for(auto i:y) x.push_back(i);
    ll t1=0,t2=0;
    for(int i=0;i<x.size();i++){
        t1+=x[i].first;
        t2=max(t1,t2)+x[i].second;
    }
    cout<<t2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}