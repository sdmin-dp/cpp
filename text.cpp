#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll in[N],out[N];
ll idx[N];
ll s;
deque<ll> ans;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        in[y]++;
        out[x]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i])
    }
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