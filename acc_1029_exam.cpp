#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
unordered_map<ll,ll> mp;
unordered_map<ll,ll> remp;
pair<ll,ll> a[N];
vector<ll> sorted;
vector<ll> g[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        sorted.push_back(a[i].first);
        sorted.push_back(a[i].second);
    }
    sort(sorted.begin(),sorted.end());
    for(){

    }
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