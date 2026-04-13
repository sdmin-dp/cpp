#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll dis[N],cnt[N];
bool SPFA(){
    queue<pair<ll,ll>> q;
    vector<bool> inq(n+1,0);
    q.push({1,0});
    inq[1]=1;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        inq[x.first]=0;
        for(auto i:g[x.first]){
            if(i.first>n+1){
                return 1;
            }
            if(!inq[i.first]){
                if(x.second+i.second>dis[i.first]){
                    dis[i.first]=x.second+i.second;
                    cnt[i.first]++;
                }
                q.push(i);
            }
        }
    }
    return 0;
}
void solve(){
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