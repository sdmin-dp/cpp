#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
map<ll,ll> mp;
void solve(){
    ll n;
    cin>>n;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
    if(n!=1) mp[n]++;
    bool flag=1;
    for(auto i:mp){
        if(flag){
            if(i.second==1) cout<<i.first;
            else cout<<i.first<<'^'<<i.second;
            flag=0;
        }
        else{
            cout<<"*";
            if(i.second==1) cout<<i.first;
            else cout<<i.first<<'^'<<i.second;
        }
    }
}

int main() {
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