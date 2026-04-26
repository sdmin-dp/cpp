#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k;
//m->厂家个数
pair<ll,ll> a[N];
multiset<pair<ll,ll>> st;
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
        st.insert({a[i].second,a[i].first});
        vis[a[i].first]++;
    }
    ans+=x*x;
    ll res=ans;
    for(int i=k+1;i<=n;i++){
        if(vis[a[i].first]) continue;
        pair<ll,ll> t;
        for(auto i:st){
            if(vis[i.second]>1){
                t.first=i.second;
                t.second=i.first;
                break;
            } 
        }
        ll new_ans=ans-t.second;
        cerr<<t.first<<" "<<t.second<<" "<<a[i].first<<" "<<a[i].second<<el;
        if(vis[t.first]==1){
            new_ans-=x*x;
            x--;
            new_ans+=x*x;
        }
        vis[t.first]--;
        new_ans+=a[i].second;
        vis[a[i].first]++;
        new_ans-=x*x;
        x++;
        new_ans+=x*x;
        st.erase(st.begin());
        st.insert({a[i].second,a[i].first});
        ans=new_ans;
        res=max(res,ans);
        // cerr<<res<<" "<<ans<<" "<<a[i].first<<" "<<a[i].second<<el;
    }
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