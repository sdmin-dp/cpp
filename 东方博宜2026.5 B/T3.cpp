#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,d,a;
// pair<ll,ll> g[N];
struct node{
    ll p,v;
    bool operator < (const node b)const{
        if(b.p!=p) return p>b.p;
        else return v<b.v;
    }
};
priority_queue<node> q;
void solve(){
    cin>>n>>d>>a;
    for(int i=1;i<=n;i++){
        ll u,v;
        cin>>u>>v;
        q.push({u,v});
    }
    ll num=0,cnt=0;
    while(!q.empty()){
        auto t=q.top();
        q.pop();
        // cerr<<t.p<<" "<<t.v<<el;
        if(t.v<0){
            num+=t.v*a;
        }else if(t.v>num){
            ll x=(t.v-num)/a+((t.v-num)%a==0?0:1);
            cnt+=x;
            num+=x*a;
            q.push({t.p+2*d,-x});
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