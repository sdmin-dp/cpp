#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll m1,m2,n,l,r;
pair<ll,ll> a[N];
bool vis[N];
ll t[N];
ll lowbit(ll x){
    return x&(-x);
}
ll getsum(ll x){
    ll res=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        res+=t[i];
    }
    return res;
}
void add(ll x,ll d){
    for(int i=x;i<=n;i+=lowbit(i)){
        t[i]+=d;
    }
}
void solve(){
    cin>>m1>>m2;
    n=m1+m2;
    l=m1;
    r=m1+1;
    for(int i=m1;i>=1;i--){
        cin>>a[i].first;
        a[i].second=i;
        add(i,1);
    }
    for(int i=m1+1;i<=m1+m2;i++){
        cin>>a[i].first;
        a[i].second=i;
        add(i,1);
    }
    sort(a+1,a+n+1,greater<pair<ll,ll>>());
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll p=a[i].second;
        if(p>=r){
            if(vis[r]) ans+=getsum(p)-getsum(r)-1;
            else ans+=getsum(p)-getsum(r);
            vis[p]=1;
            r=p;
            l=r-1;
            add(p,-1);
        }
        else{
            ans+=getsum(l)-getsum(p);
            vis[p]=1;
            l=p;
            r=l+1;
            add(p,-1);
        }
    }
    cout<<ans;
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