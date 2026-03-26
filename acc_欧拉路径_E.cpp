#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
bool vis[N];
vector<ll> g[N];
map<char,vector<ll>> mp;
string s[N];
void dfs(ll x){
    for(auto i:g[x]){
        if(!vis[i]){
            vis[i]=1;
            dfs(i);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        mp[s[i][0]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        char c=s[i][s[i].size()-1];
        for(auto j:mp[c]){
            ll k=j;
            g[i].push_back(k);
            g[k].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        cerr<<"i:";
        for(auto j:g[i]){
            cerr<<j<<" ";
        }
        cerr<<el;
    }
    dfs(1);
    bool flag=1;
    for(int i=1;i<=n;i++) if(!vis[i]) flag=0;
    if(flag) cout<<"Ordering is possible.\n";
    else cout<<"The door cannot be opened.\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        mp.clear();
        for(int i=1;i<=n;i++) g[i].clear();
        solve();
        cerr<<el<<el;
    }
    return 0;
}