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
    for(int i=1;i<=n;i++) a[i].first=1e18;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        a[x].first=min(a[x].first,(ll)(i));
        a[x].second=max(a[x].second,(ll)(i));
    }
    v.push_back(0);
    for(int i=1;i<=n;i++){
        if(a[i].first!=1e18) v.push_back(a[i].first);
        if(a[i].second!=0&&a[i].second!=a[i].first) v.push_back(a[i].second); 
    }
    n=v.size()-1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            if(a[i]!=a[j]){
                ans=max(ans,llabs(j-i));
                break;
            }
        }
    }
    cout<<ans;
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