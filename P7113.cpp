#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
vector<ll> que;
ll in[N];
ll ans[N];
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll k;cin>>k;
        if(k==0) que.push_back(i); 
        for(ll j=1;j<=k;j++){
            ll x;cin>>x;
            g[i].push_back(x);
            in[x]++;
        }
    }
    queue<pair<ll,pair<ll,ll>>> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push({i,{1,1}});
        }
    }
    while(!q.empty()){
        ll u=q.front().first;
        auto [w1,w2]=q.front().second;
        w2*=g[u].size();
        for(auto v:g[u]){
            if(!(--in[v])){
                q.push({v,{w1,w2}});
            }
        }
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