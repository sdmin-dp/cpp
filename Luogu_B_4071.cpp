#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e3+5;
ll n,m;
ll cnt[N];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.second!=y.second) return x.second<y.second;
    else return cnt[x.first]>cnt[y.first];
}
pair<ll,ll> a[N];
bool check(){
    for(int i=2;i<=n;i++) if(cnt[i]>=cnt[1]) return 0;
    return 1;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;
        cnt[a[i].first]++;
    }
    sort(a+1,a+m+1,cmp);
    ll ans=0;
    for(int i=1;i<=m;i++){
        if(check()) break;
        if(a[i].first!=1&&!check()){
            cnt[a[i].first]--;
            cnt[1]++;
            a[i].first=1;
            ans+=a[i].second;
        }
    }
    cout<<ans;
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