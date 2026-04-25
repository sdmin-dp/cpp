#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define el '\n'
const ll N=1e5+5;

void solve(){
    for(int i=1;i<=10000;i++){
        cout<<i<<" ";
    }
    for(int i=1;i<=10000;i++){
        cout<<1<<" "<<10000<<" "<<i<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}