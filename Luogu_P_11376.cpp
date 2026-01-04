#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n,m,k,m1,m2;
pair<ll,ll> a[N],b1[N],b2[N];
bool cmp1(pair<ll,ll> x,pair<ll,ll> y){
    return x.first<y.first;
}
bool cmp2(pair<ll,ll> x,pair<ll,ll> y){
    return abs(x.first-x.second)>abs(y.first-y.second);
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    for(int i=1;i<=m;i++){
        pair<ll,ll> x;
        cin>>x.first>>x.second;
        if(x.first>=x.second) b1[++m1]=x;
        else b2[++m2]=x;
    }
    stable_sort(a+1,a+n+1,cmp1);
    sort(b1+1,b1+m1+1,cmp2);
    sort(b2+1,b2+m2+1,cmp2);
    ll now=1;
    ll ans=0;
    for(int i=1;i<=m1;i++){
        if(a[now].second==0) now++;
        ans+=2*(b1[i].first*a[now].first+b1[i].second*(k-a[now].first));
        a[now].second--;
    }
    now=n;
    for(int i=1;i<=m2;i++){
        if(a[now].second==0) now--;
        ans+=2*(b2[i].first*a[now].first+b2[i].second*(k-a[now].first));
        a[now].second--;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}