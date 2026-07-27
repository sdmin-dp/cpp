#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
priority_queue<ll> pq;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        pq.push(x);
    }
    for(int i=1;i<=m;i++){
        ll x=pq.top();pq.pop();
        x/=2;
        pq.push(x);
    }
    ll ans=0;
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans;
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