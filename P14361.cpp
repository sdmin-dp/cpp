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
ll cnt[3]={0,0,0};
vector<ll> loss[3];
void solve(){
    cin>>n;
    ll ans=0;
    loss[0].clear();
    loss[1].clear();
    loss[2].clear();
    cnt[0]=cnt[1]=cnt[2]=0;
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
        ans+=t.mx;
        cnt[t.kind_mx]++;
        loss[t.kind_mx].push_back(t.mx-t.cmx);
    }
    for(int i=0;i<3;i++){
        if(cnt[i]>n/2){
            ll rm=cnt[i]-n/2;
            sort(loss[i].begin(),loss[i].end());
            for(int j=0;j<rm;j++){
                ans-=loss[i][j];
            }
        }
    }
    cout<<ans<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("seat.in","r",stdin);
    // freopen("seat.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}