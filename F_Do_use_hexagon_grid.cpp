#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll dx[]={-1,-1,0,0,1,1},dy[]={-1,0,-1,1,0,1};
ll n;
pair<ll,ll> a[N];
map<pair<ll,ll>,bool> mp;
map<pair<ll,ll>,bool> vis;
void bfs(ll bx,ll by){
    queue<pair<ll,ll>> q;
    q.push({bx,by});
    while(!q.empty()){
        auto t=q.front();q.pop();
        ll x=t.first,y=t.second;
        for(int i=0;i<6;i++){
            ll xx=x+dx[i],yy=y+dy[i];
            if(mp[{xx,yy}]&&!vis[{xx,yy}]){
                vis[{xx,yy}]=1;
                q.push({xx,yy});
            }
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        mp[{a[i].first,a[i].second}]=1;
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[{a[i].first,a[i].second}]){
            vis[{a[i].first,a[i].second}]=1;
            cnt++;
            bfs(a[i].first,a[i].second);
        }
    }
    cout<<cnt;
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