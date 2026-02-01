#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
priority_queue<ll,vector<ll>,greater<ll>> q;
ll money=0;
ll sum;
void solve(){
    cin>>money>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first;
    for(int j=1;j<=n;j++){cin>>a[j].second;sum+=a[j].second;}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(q.size()>=a[i].first){
            if(a[i].second>q.top()){
                q.pop();
                q.push(a[i].second);
            }
        }
        else q.push(a[i].second);
    }
    ll cnt=0;
    while(!q.empty()){
        cnt+=q.top();
        q.pop();
    }
    cout<<money-(sum-cnt);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}