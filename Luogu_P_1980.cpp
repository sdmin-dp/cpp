#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,x;
ll cnt;
void f(ll k){
    do{
        if(k%10==x){
            cnt++;
        }
        k/=10;
    }while(k>0);
}
void solve(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        f(i);
    }
    cout<<cnt;
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