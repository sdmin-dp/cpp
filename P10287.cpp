#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N];
ll dp[N][15];
vector<ll> g[N];
ll in[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        in[v]++;
    }
    queue<ll> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
        dp[i][a[i]]=1;
    }
    while(!q.empty()){
        ll t=q.front();
        q.pop();
        for(auto i:g[t]){
            if(--in[i]==0) q.push(i);
            for(int j=1;j<=a[i];j++) if(dp[t][j]+1>dp[i][a[i]]) dp[i][a[i]]=dp[t][j]+1;
            for(int j=1;j<=10;j++) if(dp[t][j]>dp[i][j]) dp[i][j]=dp[t][j];
        }
    }
    ll ans=0;   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            ans=max(ans,dp[i][j]);
        }
    }
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