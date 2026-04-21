#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
vector<ll> v;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        v.push_back(a[i].second-a[i].first);
    }
    sort(v.begin(),v.end());
    for(auto i:v) cout<<i<<" ";
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