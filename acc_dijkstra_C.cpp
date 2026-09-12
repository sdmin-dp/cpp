#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
ll n,m,x,y,ans[1000005];
bool b[1000005];
vector<vector<ll>> v;
void solve(){
     cin>>n>>m;
    v.resize(n+5);
    vector<ll> dis(n+5,LLONG_MAX);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ans[1]=dis[1]=b[1]=1;
    queue<ll> q;q.push(1);
    while(q.size()){
        ll p=q.front();q.pop();
        b[p]=0;
        for(auto i:v[p]){
            if(dis[i]>dis[p]+1){
                dis[i]=dis[p]+1;
                ans[i]=ans[p];
                if(!b[i]){
                    q.push(i);
                    b[i]=1;
                }
            }else if(dis[i]==dis[p]+1) ans[i]=(ans[i]+ans[p])%((ll)(1e5+3));
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<el;
}
int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
