#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
set<ll> s;
ll a[25];
void solve(){
    for(int i=1;i<=20;i++) cin>>a[i];
    for(int i=1;i<=10;i++){
        for(int j=11;j<=20;j++) for(int k=i+1;k<=10;k++) for(int l=11;l<=20;l++) if(l!=j) s.insert(-a[i]+a[j]-a[k]+a[l]);
        for(int k=i;k<=10;k++) for(int l=11;l<=20;l++) s.insert(-a[k]+a[l]);
        for(int j=11;j<=20;j++) s.insert(-a[i]+a[j]);
        s.insert(0);
    }
    cout<<s.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}