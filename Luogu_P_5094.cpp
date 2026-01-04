#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e4+5;
ll n,ans;
pair<ll,ll> a[N];
ll t[N],p[N];
ll lowbit(ll x){
     return (x&-x);
}
void add(ll x,ll d){
    while(x<=N){
        t[x]+=d;
        x+=lowbit(x);
    }
}
ll getsum(ll x){
    ll res=0;
    while(x>0){
        res+=t[x];
        x-=lowbit(x);
    }
    return res;
}
void addp(ll x){
    while(x<=N){
        p[x]++;
        x+=lowbit(x);
    }
}
ll getp(ll x){
    ll res=0;
    while(x>0){
        res+=p[x];
        x-=lowbit(x);
    }
    return res;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1);
    ll ss=0;
    for(int i=1;i<=n;i++){
        ll cnt=getp(a[i].second),sum=getsum(a[i].second);
        ans+=a[i].first*(cnt*a[i].second-sum+ss-sum-(i-1-cnt)*a[i].second);
        add(a[i].second,a[i].second);
        addp(a[i].second);
        ss+=a[i].second;
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