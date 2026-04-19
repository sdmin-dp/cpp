#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;

void solve(){
    for(int i=2;i<=50000;i++){
        cout<<i<<" "<<1<<el;
    }
    for(int i=50000;i<=100000;i++){
        cout<<1<<" "<<i<<el;
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