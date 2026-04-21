#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s,t;
map<char,vector<ll>> mp;
void solve(){
    cin>>s>>t;
    s=' '+s;
    for(int i=1;i<s.size();i++) mp[s[i]].push_back(i);
    for(int i=0;i<t.size();i++){
        if(mp[t[i]].empty()){
            cout<<-1;
            return;
        }
    }
    ll ans=0;
    for(auto i:t){
        for(auto j:mp[i]){
            if(j>(ans%s.size()==0?s.size():ans%s.size())){
                
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