#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
struct bcj{
    vector<ll> fa;
    ll sum;
    bcj(ll len){
        sum=len;
        fa.reserve(len+5);
        fa.resize(len+5);
        for(int i=1;i<=len;i++) fa[i]=i;
    }
    ll find(ll x){
        if(x==fa[x]) return x;
        else return fa[x]=find(fa[x]);
    }
};
ll n,m;
void solve(){
    cin>>n>>m;
    bcj a(n);
    for(int i=1;i<=m;i++){
        ll op;
        cin>>op;
        if(op==1){
            ll u,v;
            cin>>u>>v;
            ll fu=a.find(u),fv=a.find(v);
            if(fu!=fv){
                a.sum--;
                a.fa[fu]=fv;
            }
        }else{
            cout<<a.sum<<el;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}