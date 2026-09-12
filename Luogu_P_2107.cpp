#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,ll> a[N];
priority_queue<ll> q;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1);
    ll sum=0;
    if(m==0){
        cout<<0;
        return;
    }
    for(int i=1;i<=n;i++){
        if(q.empty()){
            if(a[i].first+a[i].second<=m) q.push(a[i].second);
        }else{
            if(sum+a[i].first+a[i].second<=m) q.push(a[i].second),sum+=a[i].second;
            else if(sum+q.top()+a[i].first+a[i].second<=m){
                sum-=q.top();
                q.pop();
                sum+=a[i].second;
                q.push(a[i].second);
            }
        }
    }
    cout<<q.size();
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