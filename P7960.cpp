#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e7;
bool vis[N+3];
vector<int>v;
bool check(ll x){
    string s=to_string(x);
    for(auto i:s) if(i=='7') return 0;
    return 1;
}
void solve(){
    ll n;
    cin>>n;
    for(ll i=2;i<=N;i++){
        if(!vis[i]) v.push_back(i);
        if(vis[i]) continue;
        if(!check(i))
            for(ll j=i;j<=N;j+=i)
                vis[j]=1;
    }
    while(n--){
        ll x;cin>>x;
        if(vis[x]==1){
            cout<<-1<<el;
            continue;
        }
        ll ans=v[upper_bound(v.begin(),v.end(),x)-v.begin()];
        cout<<ans<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}