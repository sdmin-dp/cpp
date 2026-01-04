#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
vector<pair<ll,ll>> g[N];
stack<ll> stk;
ll a[N];
string s[N];
bitset<32> bs;
ll ans=0;
ll trie[32*N+5][2];
ll idx;
void insert(string &s){
    int p=0;
    for(auto i:s){
        auto x=i-'0';
        if(!trie[p][x]) trie[p][x]=++idx;
        p=trie[p][x];
    }
}
void dfs(int x,int fa){
    for(auto i:g[x]){
        ll v=i.first,w=i.second;
        if(v!=fa){
            a[v]=a[stk.top()]^w;
            stk.push(v);
            dfs(v,x);
            stk.pop();
        }
    }
}
ll find(string &s){
    int p=0,res=0;
    for(auto i:s){
        auto x=i-'0';
        if(trie[p][!x]) res=res*2+1,p=trie[p][!x];
        else res*=2,p=trie[p][x];
    }
    return res;
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    stk.push(1);
    dfs(1,0);
    for(int i=1;i<=n;i++){
        bs=a[i];
        s[i]=bs.to_string();
        insert(s[i]);
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,find(s[i]));
    }
    cout<<ans;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}