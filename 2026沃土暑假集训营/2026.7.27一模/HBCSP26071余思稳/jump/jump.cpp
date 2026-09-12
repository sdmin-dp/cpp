#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,k;
ll a[N];
priority_queue<pair<ll,ll>> q;
ll ans;
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    q.push({0,0});
    for(int i=1;i<=n;i++){
        while(q.top().second+k<i){
            q.pop();
        }
        ll sc=q.top().first;
        q.push({sc+a[i],i});
        if(i==n){
            ans=sc+a[i];
        }
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