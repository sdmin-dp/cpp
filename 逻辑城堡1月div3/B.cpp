#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
vector<ll> v;
void solve(){
    cin>>n;
    ll x=n;
    do{
        ll k=x%2;
        v.push_back(k);
        x/=2;
    }while(x);
    for(auto i:v) cerr<<i;
    ll i=0;
    cout<<n<<"=";
    for(auto &j:v){
        if(j){
            if(i==0){
                cout<<(1<<i);
            }else{
                cout<<"+"<<(1<<i);
            }
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