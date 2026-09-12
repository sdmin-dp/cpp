#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
map<ll,multiset<ll>> mp;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll op;
        cin>>op;
        if(op==1){
            ll c,p;
        
    cin>>c>>p;
            mp[c].insert(p);
        }else if(op==2){
            ll c,p;
            cin>>c>>p;
            mp[c].erase(mp[c].lower_bound(p));
        }else{
            ll c;
            cin>>c;
            if(mp[c].empty()) cout<<"-1 -1"<<el;
            else cout<<(*mp[c].begin())<<" "<<(*mp[c].rbegin())<<el;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("route.in","r",stdin);
    freopen("route.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}