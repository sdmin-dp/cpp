#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll ans=0;
ll a[N];
vector<pair<ll,ll>> res;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]>a[j]){
                res.push_back({i,j});
                swap(a[i],a[j]);
                ans++;
            }
        }
    }
    // for(int i=1;i<=n;i++) cerr<<a[i]<<" ";
    cout<<ans<<el;
    for(auto i:res){
        cout<<i.first<<" "<<i.second<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xxx.in","r",stdin);
    freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}