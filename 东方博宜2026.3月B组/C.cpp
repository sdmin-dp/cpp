#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s,t;
vector<ll> mp[500];
void solve(){
    cin>>s>>t;
    for(int i=0;i<s.size();i++) mp[s[i]].push_back(i+1);
    for(int i=0;i<t.size();i++){
        if(mp[t[i]].empty()){
            cout<<-1;
            // cerr<<t[i]<<" ";
            return;
        }
    }
    ll ans=0;
    for(auto i:t){
        // cerr<<i<<" ";
        bool f=0;
        ll pos=upper_bound(mp[i].begin(),mp[i].end(),ans%s.size())-mp[i].begin();
        // cerr<<pos<<el;
        if(pos!=mp[i].size()) f=1;
        if(f){
            f=1;
            ans=(ans/s.size())*s.size()+mp[i][pos];
        }
        if(!f){
            if(ans%s.size()!=0) ans=(ans/s.size()+1)*s.size();
            ans+=mp[i][0];
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