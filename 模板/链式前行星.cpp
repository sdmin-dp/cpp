#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
struct node{
    ll to,next;
}e[N];
ll h[N],in[N];
ll cnt=0;
ll n,m;
void add(ll u,ll v){
    ++cnt;
    e[cnt].to=v;
    e[cnt].next=h[u];
    h[u]=cnt;
}
void tpsort(){
    queue<ll> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        ll t=q.front();
        q.pop();
        cout<<t<<" ";
        for(int i=h[t];i;i=e[i].next){
            ll to=e[i].to;
            if(--in[to]==0){
                q.push(to);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        add(u,v);
        in[v]++;
    }
    tpsort();
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