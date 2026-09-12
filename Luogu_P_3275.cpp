#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
vector<ll> dis(N,-1e18);  // 使用更小的初始值
vector<ll> vis(N);
ll cnt[N];

void SPFA(){
    queue<ll> q;
    // 建立超级源点0，连接到所有点，权值为1
    for(int i=1;i<=n;i++){
        g[0].push_back({i,1});
    }
    
    q.push(0);
    vis[0]=1;
    dis[0]=0;
    
    while(!q.empty()){
        ll x=q.front();q.pop();
        vis[x]=0;
        for(auto i:g[x]){
            if(dis[i.first]<dis[x]+i.second){
                dis[i.first]=dis[x]+i.second;
                cnt[i.first]=cnt[x]+1;
                
                // 如果路径长度超过n+1（包括超级源点），说明有正环
                if(cnt[i.first]>=n+1){
                    cout<<-1;
                    exit(0);
                }
                if(!vis[i.first]){
                    q.push(i.first);
                    vis[i.first]=1;
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll op,A,B;
        cin>>op>>A>>B;
        
        // 先检查非法情况
        if(op==2&&A==B){
            cout<<-1;
            return;
        }
        if(op==4&&A==B){
            cout<<-1;
            return;
        }
        
        switch(op){
            case 1:
                g[A].push_back({B,0});
                g[B].push_back({A,0});
                break;
            case 2:
                g[A].push_back({B,1});
                break;
            case 3:
                g[B].push_back({A,0});
                break;
            case 4:
                g[B].push_back({A,1});
                break;
            case 5:
                g[A].push_back({B,0});
                break;
        }
    }
    
    memset(cnt,0,sizeof(cnt));
    SPFA();
    
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=dis[i];
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}