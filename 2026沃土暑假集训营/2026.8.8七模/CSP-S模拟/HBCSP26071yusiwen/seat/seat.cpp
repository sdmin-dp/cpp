#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
struct node{
    ll mx,cmx,kind_mx,kind_cmx;
    bool operator<(const node b)const{
        return mx-cmx<b.mx-b.cmx;
    }
};
ll n;
priority_queue<node> q;
void solve(){
    cin>>n;
    ll ans=0;
    ll cnt[3]={0,0,0};
    for(int i=1;i<=n;i++){
        vector<pair<ll,ll>> v(3);
        cin>>v[0].first>>v[1].first>>v[2].first;
        v[0].second=0;v[1].second=1;v[2].second=2;
        sort(v.begin(),v.end(),greater<pair<ll,ll>>());
        node t;
        t.mx=v[0].first;
        t.kind_mx=v[0].second;
        t.cmx=v[1].first;
        t.kind_cmx=v[1].second;
        if(cnt[t.kind_mx]==n/2){
            auto x=q.top();
            if(x<t){
                ans-=(x.mx-x.cmx);
                q.pop();
                q.push(t);
                ans+=t.mx;
                cnt[x.kind_mx]--;
                cnt[x.kind_cmx]++;
                cnt[t.kind_mx]++;
            }else{
                ans+=t.cmx;
                cnt[t.kind_cmx]++;
            }
        }else{
            ans+=t.mx;
            q.push(t);
            cnt[t.kind_mx]++;
        }
        //cerr<<ans<<el;
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}