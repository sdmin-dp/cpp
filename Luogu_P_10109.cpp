#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e2+5;
const ll Q=1e2+5;
ll n;
ll f[N];
ll q;
ll vis[Q][N];
void bfs(ll x,ll k){
    vis[k][x]++;
    while(x!=0){
        x=f[x];
        vis[k][x]++;
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++) cin>>f[i];
    cin>>q;
    for(int i=1;i<=q;i++){
        ll m,x;
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>x;
            bfs(x,i);
        }
        ll ans;
        for(int j=0;j<n;j++){
            if(vis[i][j]==m){
                ans=j;
            }
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}