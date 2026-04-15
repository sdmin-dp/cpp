#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
struct bcj{
    vector<ll> fa;
    bcj(ll len){
        fa.reserve(len+5);
        fa.resize(len+5);
        for(int i=1;i<=len;i++) fa[i]=i;
    }
    ll find(ll x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
    }
};
ll len[N];
ll n;
void solve(){
    cin>>n;
    bcj a(n);
    ll ans=0;
    for(int i=1;i<n;i++){
        ll x,y,z;cin>>x>>y>>z;
        int fx=a.find(x),fy=a.find(y);
        ans+=llabs(len[fx]-len[fy])*z;
        a.fa[fy]=fx;
        len[fx]+=len[fy];
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