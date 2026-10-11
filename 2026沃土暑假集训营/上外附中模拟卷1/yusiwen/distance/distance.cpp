#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
void solve(){
    cin>>n;
    if(n==1){
        cout<<0;
        return;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    ll mx=-1e12;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            mx=max(mx,abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second));
    cout<<mx;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("distance.in","r",stdin);
    freopen("distance.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}