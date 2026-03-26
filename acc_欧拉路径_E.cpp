#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=30;
ll n;
bool vis,exists;
vector<ll> g;
ll in,out;
void dfs(ll x){
    vis[x]=1;
    for(auto i:g[x]){
        if(!vis[i]) dfs(i);
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<26;i++){
        g[i].clear();
        vis[i]=0;
        exists[i]=0;
        in[i]=0;
        out[i]=0;
    }
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int u=s[0]-'a';
        int v=s[s.size()-1]-'a';
        g[u].push_back(v);
        g[v].push_back(u);
        out[u]++;
        in[v]++;
        exists[u]=exists[v]=1;
    }
    int st=-1;
    for(int i=0;i<26;i++){
        if(exists[i]){
            st=i;
            break;
        }
    }
    if(st!=-1) dfs(st);
    for(int i=0;i<26;i++){
        if(exists[i]&&!vis[i]){
            cout<<"The door cannot be opened."<<el;
            return;
        }
    }
    int s_cnt=0,e_cnt=0;
    bool ok=1;
    for(int i=0;i<26;i++){
        if(!exists[i]) continue;
        if(in[i]==out[i]) continue;
        if(out[i]-in[i]==1) s_cnt++;
        else if(in[i]-out[i]==1) e_cnt++;
        else ok=0;
    }
    if(ok&&((s_cnt==0&&e_cnt==0)||(s_cnt==1&&e_cnt==1))){
        cout<<"Ordering is possible."<<el;
    }else{
        cout<<"The door cannot be opened."<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
