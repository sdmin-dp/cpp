#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k;
//m->厂家个数
pair<ll,ll> a[N];
set<pair<ll,ll>,greater<pair<ll,ll>>> st;
//由于要排序,q的pair是个反的
ll ans=0;
ll vis[N];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    return x.second>y.second;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1,cmp);
    ll x=0;
    for(int i=1;i<=k;i++){
        ans+=a[i].second;
        if(!vis[a[i].first]) x++;
        vis[a[i].first]++;
        st.insert({a[i].second,a[i].first});
    }
    ans+=x*x;
    ll res=ans;
    cout<<res;
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