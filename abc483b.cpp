#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,q;
pair<ll,ll> a[N];

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=1;
    }
    for(int i=1;i<=q;i++){
        ll x;cin>>x;
        reverse(a+1,a+x+1);
        for(int j=1;j<=x;j++){
            a[j].second = -a[j].second;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<(a[i].second==1 ? a[i].first : -a[i].first)<<el;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}