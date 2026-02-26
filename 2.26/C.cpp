#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n,m;
vector<ll> g[N];
void solve(){
    for(int i=1;i<=n;i++) g[i].clear();
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(g[i].size()%2!=0){
            cnt++;
        }
    }
    if(cnt!=0&&cnt!=2) cout<<"NO"<<el;
    else cout<<"YES"<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        
        solve();
    }
    return 0;
}