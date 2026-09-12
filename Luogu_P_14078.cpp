#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N];
pair<ll,ll> d[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i].first>>d[i].second;
    sort(d+1,d+n+1);
    for(int i=1;i<=n;i++){
        if (d[i].second-d[i].first>=0)a[++m]=d[i].second-d[i].first;
    }
    vector<ll> v;
    for(int i=1;i<=m;i++){
        ll pos=upper_bound(v.begin(),v.end(),a[i])-v.begin();
        if(pos==v.size()) v.push_back(a[i]);
        else v[pos]=a[i];
    }
    cout<<v.size();
}
int main() {
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