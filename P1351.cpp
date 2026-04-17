#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
const ll mod=10007;
ll n;
vector<ll> g[N];
ll w[N];
ll sum[N],mx[N];
ll ans,res;//ans->max ans ,res->sum
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        if(i!=fa){
            sum[i]+=w[i];
            mx[i]=max(mx[i],w[i]);
        }
    }
}
void dfs2(ll x,ll fa){
    for(auto i:g[x]){

    }
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++) cin>>w[i];

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