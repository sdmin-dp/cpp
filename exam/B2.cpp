#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
pair<ll,ll> a[N];
map<ll,ll> mpx;
map<ll,ll> mpy;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        mpx[a[i].first]++;
        mpy[a[i].second]++;
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=(mpx[a[i].first]-1)*(mpy[a[i].second]-1);
    }
    cout<<sum;
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