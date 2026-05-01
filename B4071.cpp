#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll n;
pair<ll,ll> a[N];
ll cnt[N];
vector<ll> v[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        cnt[a[i].first]++;
        v[a[i].first].push_back(a[i].second);
    }
    for(int i=1;i<=n;i++){
        
    }
    for(int i=1;i<=n;i++){
        ll sum=cnt[1],num=0;
        for(int j=2;j<=n;j++){
            if(cnt[j]>=i){
                sum+=cnt[j]-i;

            }
        }
    }
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