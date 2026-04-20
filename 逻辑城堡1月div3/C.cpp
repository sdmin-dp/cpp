#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll find(ll x){
    for(int i=2;i*i<=x;i++) if(x%i==0) return i;
    return 0;
}
void solve(){
    cin>>n;
    for(int i=2;i*i<=n;i++){
        if(!n%i){
            cerr<<"dog";
            ll j=find(n/i);
            if(j==0) continue;
            cout<<i<<" "<<j<<" "<<(n/i)/j;
            return;
        }
    }
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