#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll in[N];
vector<ll> g[N];
ll res[N];
void topol(){
    queue<ll> q;
    for(int i=1;i<=n;i++){
        res[i]=1;
        q.push(i);
    }
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        for(auto i:g[x]){
            in[i]--;
            if(in[i]==0){
                res[i]=res[x]+1;
                q.push(i);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        in[v]++;
    }
    topol();
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}

int main() {
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