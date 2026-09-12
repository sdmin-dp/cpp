#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
ll b,e;
bool vis[N];
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({b,0});
    vis[b]=1;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        if(x.first==e){
            cout<<x.second;
            return;
        }
        if(x.first+1<=N&&!vis[x.first+1]){vis[x.first+1]=1;q.push({x.first+1,x.second+1});}
        if(x.first-1>=0&&!vis[x.first-1]){vis[x.first-1]=1;q.push({x.first-1,x.second+1});}
        if(x.first*2<=N&&!vis[x.first*2]){vis[x.first*2]=1;q.push({x.first*2,x.second+1});}
    }
}
void solve(){
    cin>>b>>e;
    bfs();
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
