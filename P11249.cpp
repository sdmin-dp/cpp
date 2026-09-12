/*
1.寻找不幸点（有三条子路都有宝物）
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
bool a[N];
vector<ll> g[N];
ll cnt[N];
bool tou[N];
void dfs(ll x,ll fa){
    if(g[x].empty()) return;
    for(auto i:g[x]){
        if(i!=fa){
            dfs(i,x);
        }
    }
    for(auto i:g[x]){
        if(i!=fa&&(a[i]||cnt[i])) cnt[x]++;
    }
}
void dfs2(ll x, ll fa) {
    if(fa!=0&&(a[fa]||tou[fa])){
        tou[x]=1;
    }
    for(auto i:g[x]) {
        if (i==fa) continue;
        bool brother_has=false;
        if (cnt[x]>1) brother_has=true; 
        else if(cnt[x]==1&&!(a[i]||cnt[i])) brother_has=true;
        if(brother_has) tou[i]=1;
        dfs2(i,x);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1,0);
    dfs2(1,0);
    if(cnt[1]>=3){
        cout<<"No"<<el;
        return;
    }
    for(int i=2;i<=n;i++){
        if(cnt[i]+tou[i]>=3){
            cout<<"No"<<el;
            return;
        }
    }
    cout<<"Yes";
    cout<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        memset(tou,0,sizeof(tou));
        solve();
    }
    return 0;
}