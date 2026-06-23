#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll dot[N],in[N];
ll dp[N][15];
vector<ll> g[N];
void topu(){
    queue<ll> q;
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto i:g[x]){
                for(int j=1;j<=10;j++)
                    if(j<=dot[i])
                        dp[i][dot[i]]=max(dp[i][dot[i]],dp[x][j]+1);
            for(int j=1;j<=10;j++)
                dp[i][j]=max(dp[i][j],dp[x][j]);
            if(!--in[i]){
                q.push(i);
            }
        }
    }
    
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>dot[i];
        // for(int j=1;j<=10;j++) dp[i][j]
        dp[i][dot[i]]=1;
    }
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        in[v]++;
    }
    topu();
    ll ans=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=10;j++) ans=max(ans,dp[i][j]);
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