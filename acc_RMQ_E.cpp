#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
ll n,m,p;
pair<ll,ll> a[N];
ll color[55];
ll mxprice[55];
ll cnt;
void solve(){
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=1;i<=n;i++){
        if(a[i].second<=p){
            cnt+=color[a[i].first]++;
        }
        else{
            ll k=mxprice[a[i].first];
            cnt+=color[k]
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
