#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N];
ll mx=-1e9;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        mx=max(mx,a[i]);
    }
    for(int i=m+1;i<=n;i++){
        if(a[i]>mx){
            cout<<a[i];
            return;
        }
    }
    cout<<a[n];
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