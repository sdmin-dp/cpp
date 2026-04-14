#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e4+5;
ll n,m,bod;
ll mon[N];
vector<pair<ll,ll>> g[N];
bool inq[N];
ll dis[N];
bool check(ll mid){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,1});
    if(mon[1]>mid) return 0;
    memset(inq,0,sizeof inq);
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    inq[1]=1;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        if(!inq[x.second]) continue;
        inq[x.second]=0;
        if(x.first>dis[x.second]) continue;
        for(auto i:g[x.second]){
            if(mon[i.first]<=mid&&dis[i.first]>x.second+i.second){
                dis[i.first]=x.second+i.second;
                q.push({dis[i.first],i.first});
                inq[i.first]=1;
            }
        }
    }
    return (dis[n]<=bod||dis[n]==0x3f3f3f3f3f3f3f3f);
}
ll binary_answer(){
    if(!check(1e9)) return -1;
    ll l=0,r=1e9,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            //活着
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m>>bod;
    for(int i=1;i<=n;i++) cin>>mon[i];
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    ll ans=binary_answer();
    if(ans==-1) cout<<"AFK";
    else cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("P1462_5.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}