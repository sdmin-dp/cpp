#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n,m;
vector<ll> g[N];
bool vis[N];
void dfs(ll x){
    for(auto i:g[x]){
        if(!vis[i]){
            vis[i]=1;
            dfs(i);
        }
    }
}
void solve(){
    while(cin>>n){
        cin>>m;
        if(n==0) return;
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1);
        bool flag=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cout<<0<<el;
                flag=1;
            }
        }
        if(!flag){
            ll cnt=0;
            for(int i=1;i<=n;i++) if(g[i].size()%2==1) cnt++;
            if(cnt==0) cout<<1<<el;
            else cout<<0<<el;
        }
    }

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