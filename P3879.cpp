#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
string s;
map<string,vector<ll>> mp;
vector<string> v;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll l;
        cin>>l;
        v.clear();
        for(int i=1;i<=l;i++){
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(auto &j:v){
            mp[j].push_back(i);
        }
    }
    ll m;
    cin>>m;
    for(int i=1;i<=m;i++){
        // cerr<<m<<el;
        string t;
        cin>>t;
        // cerr<<mp[t].size()<<el;
        for(auto &j:mp[t]){
            cout<<j<<" ";
        }
        cout<<el;
    }
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