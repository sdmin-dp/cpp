#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
pair<ll,ll> a[N];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.second!=y.second) return x.second<y.second;
    else return x.first<y.first;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        ll x,y;cin>>x>>y;
        a[i].second=x+y;
    }
    sort(a+1,a+n+1,cmp);
    ll last=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i].first>=last){
            last=a[i].second;
            cnt++;
        }
    }
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("schedule.in","r",stdin);
    freopen("schedule.out","w",stdout);
    ll T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
