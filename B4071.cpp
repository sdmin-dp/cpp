#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n,m;
pair<ll,ll> a[N];
ll cnt[N];
vector<ll> v[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        cnt[a[i].first]++;
        v[a[i].first].push_back(a[i].second);
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
    }
    ll ans=1e18;
    vector<ll> v2;
    for(int i=max(1ll,cnt[1]);i<=m;i++){
        ll sum=cnt[1],num=0;
        v2.clear();
        for(int j=2;j<=n;j++){
            if(cnt[j]>=i){
                sum+=cnt[j]-i+1;
                for(int k=0;k<=cnt[j]-i;k++){
                    num+=v[j][k];
                }
            }
            for(int k=cnt[j]-i+1;k<v[j].size();k++){
                    v2.push_back(v[j][k]);
                }
        }
        if(v2.size()+sum<i) continue;
        sort(v2.begin(),v2.end());
        for(auto k:v2){
            if(sum>=i) break;
            num+=k;
            sum++;
        }
        ans=min(ans,sum);
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