#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
map<char,ll> mp;
void solve(){
    ll x,y,z,X,Y,Z;
    cin>>X>>Y>>Z;
    x=min({X,Y,Z});
    z=max({X,Y,Z});
    y=X+Y+Z-x-z;
    mp['A']=x;mp['B']=y;mp['C']=z;
    char a,b,c;
    cin>>a>>b>>c;
    cout<<mp[a]<<" "<<mp[b]<<" "<<mp[c];
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