#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e2+5;
ll n;
pair<ll,ll> a[N];
bool vis[N];
ll ans;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].second;
    for(int i=1;i<=n;i++) cin>>a[i].first;
    sort(a+1,a+n+1,greater<pair<ll,ll>>());
    for(int i=1;i<=n;i++){
        for(int j=a[i].second;j>=1;j--){
            if(!vis[j]){
                ans+=a[i].first;
                vis[j]=1;
                break;
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}