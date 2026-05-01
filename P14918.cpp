#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
vector<ll> v[N];
void fenjie(ll x){
    ll k=x;
    for(ll i=2;i*i<=k;i++){
        ll cnt=0;
        while(k%i==0){
            cnt++;
            k/=i;
        }
        v[i].push_back(cnt);
    }
    if(k){
        v[k].push_back(1);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fenjie(a[i]);
    }
    ll ans=0;
    for(int i=0;i<N-5;i++){
        sort(v[i].begin(),v[i].end());
        ll mid=v[i][v[i].size()/2+1];
        for(auto &i:v[i]){
            ans+=abs(i-mid);
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