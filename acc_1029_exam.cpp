#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
set<ll>s;
unordered_map<ll,ll> mp;
unordered_map<ll,ll> remp;
pair<ll,ll> a[N];
vector<ll> g[N];
ll vis[N];
ll match[N];
bool dfs(ll u,ll id){
    for(auto i:g[u]){
        if(vis[i-2*n]!=id){
            vis[i-2*n]=id;
            if(!match[i-2*n]||dfs(match[i-2*n],id)){
                match[i-2*n]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        s.insert(a[i].first);
        s.insert(a[i].second);
    }
    
    ll I=0;
    for(auto &j:s){
        remp[++I]=j;
        mp[j]=I;
    }
    for(int i=1;i<=n;i++){
        g[mp[a[i].first]].push_back(i+2*n);
        g[mp[a[i].second]].push_back(i+2*n);
    }
    ll cnt=0;
    for(int i=1;i<=s.size();i++){
        if(dfs(i,i)) cnt++;
        if(cnt==n){
            cout<<remp[i];
            return;
        }
    }
    cout<<-1;
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