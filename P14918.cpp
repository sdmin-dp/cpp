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
            cnt++;;
            k/=i;
        }
        if(cnt) v[i].push_back(cnt);
    }
    if(k>1){
        v[k].push_back(1);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fenjie(a[i]);
    }
    // for(int i=1;i<10;i++){
    //     cerr<<i<<":";
    //     for(auto j:v[i]){
    //         cerr<<j<<" ";
    //     }
    //     cerr<<el;
    // }
    ll ans=0;
    for(int i=0;i<N;i++){
        if(v[i].empty()) continue;
        sort(v[i].begin(),v[i].end());
        ll mid;
        if(v[i].size()*2<=n) mid=0; 
        else mid=v[i][v[i].size()-n+n/2];
        for(auto j:v[i]){
            ans+=abs(j-mid);
        }
    }
    cout<<ans+2;
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