#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=15+5;
ll n;
bool vis[N];
void dfs(string s,ll x){
    if(x==n+1){
        cout<<s<<el;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            s.push_back(char(i+48));
            dfs(s,x+1);
            vis[i]=0;
            s.pop_back();
        }
    }
}
void solve(){
    cin>>n;
    dfs("",1);
}
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}