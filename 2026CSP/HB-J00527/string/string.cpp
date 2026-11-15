#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
deque<pair<ll,char>> q;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        pair<ll,char> x;
        cin>>x.first>>x.second;
        q.push_back(x);
    }
    ll ans=0;
    while(q.size()>1){
        auto l=q.front(),r=q.back();
        q.pop_back();q.pop_front();
        ll mn=min(l.first,r.first);
        if(l.second==r.second){
            l.first-=mn,r.first-=mn;
        }else{
            l.first-=mn,r.first-=mn;
            ans+=mn;
        }
        if(l.first!=0) q.push_front(l);
        if(r.first!=0) q.push_back(r);
    }
    cout<<ans<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}