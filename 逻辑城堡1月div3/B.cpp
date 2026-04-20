#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
deque<ll> dq;
void solve(){
    cin>>n;
    ll x=n;
    do{
        ll k=x%2;
        dq.push_front(k);
        k/=2;
    }while(n);
    ll i=0;
    cout<<n<<"=";
    for(auto &j:dq){
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