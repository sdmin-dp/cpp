#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
const ll p=1e9+7;
ll fa[N];
ll pre[N],nxt[N];
ll n,m;
ll find(ll x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        ll a,b;
        cin>>a>>b;
        if(pre[b]==a||nxt[a]==b) continue;
        if(pre[b]||nxt[a]||find(a)==find(b)){
            cout<<0<<el;
            return;
        }
        ll A=find(a),B=find(b);
        if(A!=B) fa[B]=A;
        pre[b]=a;nxt[a]=b;
        --n;
    }
    ll ans=1;
    for(int i=1;i<=n;i++) ans=ans*i%p;
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