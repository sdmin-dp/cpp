#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
pair<ll,pair<ll,ll>> a[N];
class bcj{
    public:
        vector<ll> fa;
        bcj(ll v){
            fa.resize(v+5);
            for(int i=1;i<=v;i++) fa[i]=i;
        }
        ll find(ll x){
            if(x==fa[x]) return x;
            return fa[x]=find(fa[x]);
        }
        void add(ll x,ll y){
            x=find(x),y=find(y);
            if(x!=y) fa[x]=y;
        }
};
ll n,m,k;
void solve(){
    cin>>n>>m>>k;
    bcj g(n);
    for(int i=1;i<=m;i++){
        cin>>a[i].second.first>>a[i].second.second>>a[i].first;
    }
    sort(a+1,a+m+1);
    ll cnt=n,ans=0;
    for(int i=1;i<=m&&cnt>k;i++){
        if(g.find(a[i].second.first)!=g.find(a[i].second.second)){
            g.add(a[i].second.first,a[i].second.second);
            cnt--;
            ans+=a[i].first;
            // cout<<a[i].first<<" ";
        }
    }
    if(cnt==k) cout<<ans;
    else cout<<"No Answer";
}

int main() {
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