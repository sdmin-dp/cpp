#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a[8];
void solve(){
    for(int i=1;i<=7;i++){
        ll x,y;
        cin>>x>>y;
        a[i]=x+y;
        if(a[i]>8) a[i]-=8;
        else a[i]=0;
    }
    ll mx=0,id=0;
    for(int i=1;i<=7;i++){
        if(a[i]>mx){
            mx=a[i];
            id=i;
        }
    }
    cout<<id;
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