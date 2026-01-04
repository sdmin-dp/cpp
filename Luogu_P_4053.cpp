#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e6+5;
ll n;
pair<ll,ll> a[N];
priority_queue<ll> q;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].second>>a[i].first;
    sort(a+1,a+n+1);
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(sum+a[i].second<a[i].first){
            q.push(a[i].second);
            sum+=a[i].second;
        }else if(q.top()>a[i].second){
            sum-=q.top();q.pop();
            sum+=a[i].second;q.push(a[i].second);
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