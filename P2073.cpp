#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
map<ll,ll> mp;
void solve(){
    while(1){
        ll op;
        cin>>op;
        if(op==-1) break;
        if(op==1){
            ll w,c;
            cin>>w>>c;
            if(!mp.count(c)) mp[c]=w;
        }else if(op==3){
            if(mp.empty()) continue;
            mp.erase(mp.begin());
        }else if(op==2){
            if(mp.empty()) continue;
            auto it=mp.end();
            it--;
            mp.erase(it);
        }
    }
    ll ans1=0,ans2=0;
    for(auto i:mp){
        ans1+=i.first;
        ans2+=i.second;
    }
    cout<<ans2<<" "<<ans1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}