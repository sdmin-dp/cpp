#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
ll n,k,tt;
pair<ll,ll> a[N];
bool u[N];
ll ans=0;

void dfs(ll x, vector<ll> v){
    if(x==k){
        sort(v.begin(),v.end());
        ll mn=1e12;
        for(int i=0;i<(ll)v.size()-1;i++){
            mn=min(mn,v[i+1]-v[i]);
        }
        ans=max(ans,mn);
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(!u[a[i].first]){
            u[a[i].first]=1;
            v.push_back(a[i].second);
            dfs(x+1,v);
            v.pop_back();
            u[a[i].first]=0;
        }
    }
}
void solve(){
    cin>>n>>k>>tt;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    memset(u,0,sizeof(u));
    dfs(0,{});
    cout<<ans<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
