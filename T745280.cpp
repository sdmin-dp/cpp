#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
pair<ll,ll> b[N];
void solve(){
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
        if(b[a[i]].first) b[a[i]].second=i;
        else b[a[i]].first=i;
    }
    for(int i=1;i<=2*n;i++){
        if(b[a[i]].first==i){
            cout<<b[a[i]].second<<" ";
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