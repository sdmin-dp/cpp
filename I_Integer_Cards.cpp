#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
priority_queue<ll,vector<ll>,greater<ll>> q;
pair<ll,ll> a[N];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    return x.first>y.first;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        q.push(x);
    }
    for(int i=1;i<=m;i++){
        cin>>a[i].second>>a[i].first;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=a[i].second;j++){
            if(q.empty()) break;
            if(q.top()<a[i].first){
                q.pop();
                q.push(a[i].first);
            }
            else break;
        }
    }
    ll ans=0;
    while(!q.empty()){
        ans+=q.top();
        q.pop();
    }
    cout<<ans;
    for(int i=1;i<=n;i++){
        
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