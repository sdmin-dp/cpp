#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
priority_queue<ll,vector<ll>,greater<ll>> q;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i].first>q.size()) q.push(a[i].second);
        else{
            if(a[i].second>q.top()){
                q.pop();
                q.push(a[i].second);
            }
        }
    }
    ll ans=0;
    while(!q.empty()){
        ans+=q.top();
        q.pop();
    }
    cout<<ans;
}

int main() {
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