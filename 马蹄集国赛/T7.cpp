#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string s,t;
map<char,ll> mp;
void solve(){
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    ll ans=0;
    for(int i=0;i<t.size();i++){
        if(mp[t[i]]>0){
            mp[t[i]]--;
            ans++;
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