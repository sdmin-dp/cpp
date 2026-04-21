#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
priority_queue<pair<ll,ll>> q;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.second-x.first!=y.second-y.first) return (x.second-x.first)<(y.second-y.first);
    else return x.first<y.first;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1,cmp);
    ll time=0;
    for(int i=1;i<=n;i++){
        if(time<a[i].second-a[i].first){
            q.push(a[i]);
        }else{
            if(q.top().first>a[i].first){
                time-=q.top().first;
                q.pop();
                q.push(a[i]);
            }
        }
    }
    cout<<q.size();
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