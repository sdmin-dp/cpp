#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<vector<pair<ll,ll>>> g;
bool SPFA(ll b){
    queue<ll> q;
    vector<ll> dis(n+5,1e12);
    vector<bool> inq(n+5,0);
    vector<ll> cnt(n+5,0);
    dis[b]=0;inq[b]=1;cnt[b]=1;q.push(b);
    while(!q.empty()){
        auto x=q.front();q.pop();
        inq[x]=0;
        for(auto i:g[x]){
            if(dis[i.first]>dis[x]+i.second){
                dis[i.first]=dis[x]+i.second;
                cnt[i.first]++;
                inq[i.first]=1;
                if(cnt[i.first]>=n+2) return 0;
                q.push(i.first);
            }
        }
    }
    return 1;
}
void solve(){
    cin>>n>>m;
    g.clear();
    g.resize(n+5);
    for(int i=1;i<=m;i++){
        ll s,t,v;
        cin>>s>>t>>v;
        g[t].push_back({s-1,-v});
        g[s-1].push_back({t,v});
    }
    for(int i=0;i<=n;i++) g[n+1].push_back({i,0});
    if(!SPFA(n+1)) cout<<"false";
    else cout<<"true";
    cout<<el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}