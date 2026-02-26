#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
vector<ll> v;
void prime(){
    ll x=n;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            while(x%i==0){
                x/=i;
                v.push_back(i);
            }
        }
    }
    if(x) v.push_back(x);
}
void solve(){
    cin>>n;
    prime();
    bool flag=1;
    for(auto i:v){
        if(flag){
            cout<<i;
            flag=0;
        }
        else{
            cout<<"×"<<i;
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