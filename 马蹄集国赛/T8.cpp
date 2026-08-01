#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e4+5;
const ll mxlog=20;
ll n,m;
ll a[N];
pair<ll,ll> st[20][N];
ll lg[N];
void init(){
    for(int i=;i<=n;i++) lg[i]=lg[i-1]/2;
    for(int i=1;i<=n;i++) st[0][i].first=st[0][i].second=a[i];
    for(int k=1;k<=mxlog;k++){
        for(int i=1;i<=n;i++){
            st[k][i]
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll mx=-1e12,mn=1e12;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

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