#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,ll> a[N];
priority_queue<ll> q;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1);
    ll j=1;
    ll ans=0;
    for(int i=1;i<=m;i++){
        while(a[j].first<=i&&j<=n){
            q.push(a[j].second);
            j++;
        }
        if(q.empty()) continue;
        ans+=q.top();
        q.pop();
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