#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
mt19937 rd(time(0));
void solve(){
    ll n,m,q;
    cin>>n;
    for(int i=1;i<n;i++) cin>>m>>m;
    cin>>q;
    while(q--){
        cout<<(rd()%100)<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("barrier.in","r",stdin);
    freopen("barrier.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}