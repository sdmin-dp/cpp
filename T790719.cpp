#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll mn=1e12;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll t=-1e12;
        for(int j=1;j<=m;j++){
            ll x;
            cin>>x;
            t=max(t,x);
        }
        mn=min(mn,t);
    }
    cout<<mn;
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