#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
void solve(){
    cin>>n>>m;
    ll cnt=0;
    if(n>=m){
        cnt=n/m;
        if(n%m!=0) cnt++;
    }else if(n<m){
        cnt=1;       
    }
    cout<<cnt<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("shovel.in","r",stdin);
    freopen("shovel.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}