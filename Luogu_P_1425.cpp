#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll a,b,c,d;
void solve(){
    cin>>a>>b>>c>>d;
    ll x=c-a,y=d-b;
    if(y<0){
        x--;
        y+=60;
    }
    cout<<x<<" "<<y;
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