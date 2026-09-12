#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll c,p,s,n;
ll ans;
set<pair<string,pair<ll,ll>>> stt;
pair<ll,ll> a[N];
void solve(){
    cin>>c>>p>>s>>n;
    ans=c*p*s;
    for(int i=1;i<=n;i++){
        string st;
        ll x,y;
        cin>>st;
        cin>>x>>y;
        stt.insert({st,{x,y}});
    }
    for(auto i:stt){
        string st;
        ll x,y;
        st=i.first;
        x=i.second.first;
        y=i.second.second;
        if(st=="CP"){
            a[y].first++;
            ans-=s;
        }else{
            a[x].second++;
            ans-=c;
        }
    }
    for(int i=1;i<=p;i++) ans+=a[i].first*a[i].second;
    cout<<ans;
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