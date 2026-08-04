//yi jiu yuan ti,ni men shi bu shi bu xiang chu ti le?
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,h;
ll a[N];
priority_queue<pair<ll, ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
vector<ll> v;
void solve(){
    cin>>n>>h;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++){
        if(h+a[i]>=0){
            h+=a[i];
            q.push({a[i], i});
        }else{
            if(q.empty()) continue;            
            if(q.top().first<a[i]){
                h-=q.top().first;
                q.pop();
                h+=a[i];
                q.push({a[i],i});
            }
        }
    }
    cout<<q.size()<<el<<h<<el;
    while(!q.empty()){
        v.push_back(q.top().second);
        q.pop();
    }
    sort(v.begin(),v.end());
    for(auto i:v) cout<<i<<" ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("repair.in","r",stdin);
    // freopen("repair.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}