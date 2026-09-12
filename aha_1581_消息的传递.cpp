#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
ll n;
vector<ll> g[N];
ll dfn[N],low[N];
ll ins[N];
stack<ll> s;
ll idx;
ll cnt=0,len[N],color[N];
vector<ll> ng[N];
ll in[N];
void tarjan(ll x){
    dfn[x]=low[x]=++idx;
    s.push(x);
    ins[x]=1;
    for(auto i:g[x]){
        if(!dfn[i]){
            tarjan(i);
            low[x]=min(low[x],low[i]);
        }else if(ins[i]) low[x]=min(low[x],dfn[i]);
    }
    if(low[x]==dfn[x]){
        cnt++;
        ll top;
        do{
            top=s.top();
            s.pop();
            ins[top]=0;
            color[top]=cnt;
            len[cnt]++;
        }while(top!=x);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll f;
            cin>>f;
            if(f) g[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++) if(!color[i]) tarjan(i);
    for(int u=1;u<=n;u++){
        for(auto v:g[u]){
            if(color[u]!=color[v]) in[color[v]]++;
        }
    }
    ll ans=0;
    for(int i=1;i<=cnt;i++){
        if(!in[i]) ans++;
    }
    cout<<ans;
}
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
