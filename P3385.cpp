#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll dis[N],cnt[N];
bool SPFA(){
    queue<ll> q;
    vector<bool> inq(n+1,0);
    q.push(1);
    inq[1]=1;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        inq[x]=0;
        for(auto i:g[x]){
            if(cnt[i.first]>n+1){
                return 1;
            }
            if(dis[x]+i.second>dis[i.first]){
                dis[i.first]=dis[x]+i.second;
                cnt[i.first]++;
                if(!inq[i.first]) q.push(i.first);
            }
        }
    }
    return 0;
}
void solve(){
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++) g[i].clear(); 
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        if(z>=0) g[x].push_back({y,z}),g[y].push_back({x,z});
        else g[x].push_back({y,z});
    }
    cout<<(SPFA()?"YES":"NO")<<el;
}
int main(){
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