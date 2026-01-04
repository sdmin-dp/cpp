#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n,m,q;
map<ll,ll> mp;
void solve(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=q;k++){
                mp[i+j+k]++;
            }
        }
    }
    ll mx=0,id;
    for(auto i:mp){
        if(i.second>mx){
            mx=i.second;
            id=i.first;
        }
    }
    cout<<id;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}