#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k; 
pair<ll,ll> a[N];
ll inq[N];
bool vis[N];
ll cnt,sum;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
void ding(auto i,auto top){
    q.pop();
    q.push(a[i]);
    inq[top.second]--;if(inq[top.second]==0) cnt--;
    if(inq[a[i].second]==0) cnt++;
    inq[a[i].second]++;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].second>>a[i].first;
    }   
    sort(a+1,a+n+1,greater<pair<ll,ll>>());
    for(int i=1;i<=n;i++){
        if(!inq[a[i].second]&&sum<k){
            q.push({a[i].first,a[i].second});
            cnt++;
            sum++;
            inq[a[i].second]++;
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&sum<k){
            q.push({a[i].first,a[i].second});
            if(!inq[a[i].second]) cnt++;
            sum++;
            inq[a[i].second]++;
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++) if(vis[i]) cerr<<a[i].second<<" "<<a[i].first<<el;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        auto top=q.top();
        if(inq[top.second]!=1&&inq[a[i].second]!=1||inq[top.second]==1&&inq[a[i].second]==1){
            if(a[i].first>top.first){
                ding(i,top);
            }
        }
        else if(inq[top.second]==1&&inq[a[i].second]!=1){
            if(a[i].first+(cnt-1)*(cnt-1)>top.first+(cnt*cnt)){
                ding(i,top);
            }
        }else if(inq[top.second]!=1&&inq[a[i].second]==1){
            if(a[i].first+(cnt+1)*(cnt+1)>top.first){
                ding(i,top);
            }
        }
    }
    ll ans=0;
    while(!q.empty()){
        ans+=q.top().first;
        // cerr<<q.top().first<<" ";
        q.pop();
    }
    ans+=cnt*cnt;
    cout<<ans;
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