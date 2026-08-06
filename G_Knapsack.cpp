#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> a;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        a.push_back({x,i});
    }
    sort(a.begin(),a.end(),greater<pair<ll,ll>>());
    vector<ll> ans;
    ll sum=0;
    bool flag=0;
    for(auto i:a){
        if(sum+i.first<=m){
            sum+=i.first;
            ans.push_back(i.second);
        }
        if((m+1)/2<=sum&&sum<=m){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<ans.size()<<el;
        for(auto i:ans) cout<<i<<" ";
    }else cout<<-1;
    cout<<el;
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