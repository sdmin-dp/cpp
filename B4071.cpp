#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n,m;
pair<ll,ll> a[N];
vector<ll> v[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        v[a[i].first].push_back(a[i].second);
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
    }
    ll ans=1e18;
    vector<ll> v2;
    for(int i=v[1].size();i<=m;i++){
        ll sum=0,cnt=v[1].size();
        v2.clear();
        for(int j=2;j<=n;j++){
            ll ned=max(size_t(0),v[i].size()-i+1);
            cnt+=ned;
            for(ll k=0;k<ned;k++)
                sum+=v[j][k];
            for(ll k=ned;k<v[j].size();k++)
                v2.push_back(v[j][k]);
        }
        if(v2.size()+cnt<i) continue;
        sort(v2.begin(),v2.end());
        for(int j=0;j<i-cnt;j++){
            sum+=v2[j];
        }
        cerr<<sum<<el;
        // ans=min(ans,sum);
    }
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