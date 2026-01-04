#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m;
vector<ll> v;
ll a[N];
void solve(){
    cin>>m>>n;
    ll mx=-1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for(ll i=1;i*i<=N;i++){
        if(i*i<m) continue;
        for(int j=1;j*i*i<=N;j++) v.push_back(j*i*i);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        ll pos=lower_bound(v.begin(),v.end(),a[i])-v.begin();
        if(v[pos]==a[i]) cout<<"lucky";
        else cout<<v[pos];
        cout<<el;
    }
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