#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n,m;
vector<ll> g[N];
ll dfn[N],low[N];
ll ins[N];
stack<ll> s;
ll idx;
ll cnt=0,len[N],color[N];
vector<ll> ng[N];
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
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++) if(!color[i]) tarjan(i);
}
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
