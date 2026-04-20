#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
vector<ll> ans;
void prime(ll x){
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            ans.push_back(i);
            x/=i;
        }
    }
}
void solve(){
    cin>>n;
    ans.clear();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}