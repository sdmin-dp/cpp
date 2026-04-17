#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
vector<pair<ll,ll>> res;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=1;i<=n-2;i++){
        ll x=a[i],y=a[i]+1,z=a[i]+2;
        if(x==y||y==z||x==z) continue;
        if(x>y&&y<z){
            ans++;
            if(x<z){
                res.push_back({x,y});
                swap()
            }
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