#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
bool vis[N];
vector<ll> g[N];
map<char,vector<string>> mp;
map<string,ll> id;
string s[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        mp[s[i][0]].push_back(s[i]);
        id[s[i]]=i;
    }
    for(int i=1;i<=n;i++){
        char c=s[i][s[i].size()-1];
        for(auto j:mp[c]){
            ll k=id[j];
            
        }
    }   
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        id.clear();
        mp.clear();
        for(int i=1;i<=n;i++) g[i].clear();
        solve();
    }
    return 0;
}