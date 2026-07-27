#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
map<string,string> mp;
ll n;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;i++) {
        string old,neww;
        cin>>old>>neww;
        bool f=0;
        for(auto &x:mp) {
            if(x.second==old) {
                x.second=neww;
                f=1;
                break;
            }
        }
        if(!f) mp[old]=neww;
    }
    cout<<mp.size()<<el;
    for(auto i:mp) cout<<i.first<<" "<<i.second<<el;
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