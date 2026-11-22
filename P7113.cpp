#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
vector<ll> que;
ll in[N];
pair<ll,ll> ans[N];
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll k;cin>>k;
        if(k==0) que.push_back(i); 
        for(ll j=1;j<=k;j++){
            ll x;cin>>x;
            g[i].push_back(x);
            in[x]++;
        }
    }
    queue<ll> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
            ans[i]={1,1};
        }
    }
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        ll w1=ans[u].first,w2=ans[u].second*g[u].size();
        for(auto v:g[u]){
            ans[v].first*=w2;
            ans[v].first+=w1*ans[v].second;
            ans[v].second*=w2;
            if(!--in[v]){
                q.push(v);
            }
        }
    }
    for(auto i:que){
        ll gcd=__gcd(ans[i].first,ans[i].second);
        ans[i].first/=gcd;
        ans[i].second/=gcd;
        cout<<ans[i].first<<" "<<ans[i].second<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}