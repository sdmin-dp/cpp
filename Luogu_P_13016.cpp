#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll x,y;
ll lstm(ll k){
    for(int i=2;i*i<=k;i++){
        if(k%i==0){
            return (k/i);
        }
    }
    return 1;
}
ll LCA(ll x,ll y){
    ll cnt=0;
    while(x!=y){
        if(x>y) x=lstm(x);
        else y=lstm(y);
        cnt++;
    }
    return cnt;
}
void solve(){
    cin>>x>>y;
    cout<<LCA(x,y)<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}