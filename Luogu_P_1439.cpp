#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
map<ll,ll> mp;
ll x;
ll b[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        mp[x]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        b[i]=mp[x];
    }
    vector<ll> v;
    for(int i=1;i<=n;i++){
        x=b[i];
        ll pos=lower_bound(v.begin(),v.end(),x)-v.begin();
        if(pos==v.size()) v.push_back(x);
        else v[pos]=x;
    }
    cout<<v.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}