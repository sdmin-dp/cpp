#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
vector<ll> g[N];
ll ans[N];
ll in[N];
ll pre[N];
void topol(){
    queue<ll> q;
    for(int i=1;i<=n;i++){
        ans[i]=a[i];
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(auto &v:g[u]){
            if(ans[u]+a[v]>ans[v]){
                ans[v]=ans[u]+a[v];
                pre[v]=u;
            }
            if(--in[v]==0) q.push(v);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ll x;cin>>x;
            if(x==1){ g[i].push_back(j); in[j]++; }
        }
    }
    topol();
    ll mx=0,id=0;
    for(int i=1;i<=n;i++){
        cerr<<ans[i]<<" ";
        if(ans[i]>mx){
            mx=ans[i];
            id=i;
        }
    }
    vector<ll> res;
    ll cur=id;
    while(cur!=0){
        res.push_back(cur);
        cur=pre[cur];
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<(int)res.size();i++){
        if(i) cout<<" ";
        cout<<res[i];
    }
    cout<<el<<mx;
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