#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll b1=0.01;
ll n,m,b,e;
vector<pair<ll,double>> g[N];
double dis[N];
void SPFA(){
    dis[b]=1;
    queue<ll> q;
    q.push(b);
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto i:g[x]){
            if(dis[i.first]<dis[x]*i.second){
                dis[i.first]=dis[x]*i.second;
                q.push(i.first);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        double w;
        cin>>u>>v>>w;
        g[u].push_back({v,(100.0-w)/100});
        g[v].push_back({u,(100.0-w)/100});
    }
    cin>>b>>e;
    SPFA();
    printf("%.8lf",100.0/dis[e]);
    // cout<<dis[e];
}

int main() {
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