#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,T,n,d,a[2000006],ans;vector<vector<ll>> g;
void bfs(ll s){
    vector<pair<ll,ll>> dis(n+3,{LLONG_MAX,0});
    queue<ll> q;
    dis[s]={0,1};q.push(s);
    while(q.size()){
        ll u=q.front();q.pop();
        for(ll v:g[u]){
            if(dis[v].first>dis[u].first+1){
                dis[v].first=dis[u].first+1,dis[v].second=dis[u].second;
                q.push(v);
            }else if(dis[v].first==dis[u].first+1) dis[v].second+=dis[u].second;
        }
    }
    for(auto x:dis) if(x.second==2) ans++;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;ans=0;g.resize(n+3);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=2;j<=n;j++){
                if(a[j]-a[i]<=d) g[i].push_back(j);
                else break;
            }
        }
        for(int i=1;i<=n;i++)bfs(i);
        cout<<ans<<'\n';g.clear();
    }
    return 0;
}
