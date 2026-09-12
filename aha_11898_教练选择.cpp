#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,ll> a[N];
ll ans[N];
ll match[N];
ll res=0;
void dfs(ll x){
    ll u=a[x].first,v=a[x].second;
    if(match[u]==0){
        //匹配成功，走人
        match[u]=x;
        res++;
    }
    else if(match[u]>x){
        ll t=match[u];
        res--;
        match[u]=x;//抢走你的教练
        res++;
        dfs(t);
    }else{
        if(match[v]==0){
            //我的备选还在（^_^）
            res++;
            match[v]=x;
        }else if(match[v]>x){
            //抢回我的备选！
            ll t=match[v];
            res--;
            match[v]=x;//抢走你的教练
            res++;
            dfs(t); 
        }
    }
    //抢不回来！我只能走人啦（www...）
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=n;i>=1;i--){
        dfs(i);
        ans[i]=res;
        // cerr<<res;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}