#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
pair<ll,ll> a[N];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.second!=y.second) return x.second<y.second;
    else return x.first<y.first;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+m+1,cmp);
    ll t=0,cnt=0;
    for(int i=1;i<=m;i++){
        if(!(a[i].first<t)){
            cnt++;
            t=a[i].second;
        }
    }
    cout<<cnt;
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