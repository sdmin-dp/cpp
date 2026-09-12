#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
void solve(){
    ll n;
    multiset<ll> ms[3];
    ll cnt[3];
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        ll k;
        if(a>=b&&a>=c) k=0,ans+=a;
        else if(b>=a&&b>=c) k=1,ans+=b;
        else k=2,ans+=c;
        cnt[k]++;
        ms[k].insert(max({a,b,c})-(a+b+c-max({a,b,c})-min({a,b,c})));
    }
    ll id=-1;
    for(int i=0;i<3;i++){
       if(cnt[i]>n/2) id=i;
    }
    if(id==-1) cout<<ans<<"\n";
    else{
        auto p=ms[id].begin();
        ll m=cnt[id]-n/2;
        for(int i=1;i<=m;i++){
            cout<<i;
            ans-=*p;
            p++;
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}