#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
pair<ll,ll> a[N];//价值,截止日期
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    if(x.second!=y.second) return x.second<y.second;
    else return x.first>y.first;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].second>>a[i].first;
    }
    sort(a+1,a+n+1,cmp);
    ll last=0,ans=0;
    for(int i=1;i<=n;i++){
        if(last+1<=a[i].second){
            ans+=a[i].first;
            q.push(a[i]);
            last++;
        }else{
            auto t=q.top();q.pop();
            ans-=t.first;last--;
            if(t.first<a[i].first){
                q.push(a[i]);
                ans+=a[i].first;
                last++;
            }else{
                ans+=t.first;
                q.push(t);
                last++;
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("project.in","r",stdin);
    freopen("project.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}