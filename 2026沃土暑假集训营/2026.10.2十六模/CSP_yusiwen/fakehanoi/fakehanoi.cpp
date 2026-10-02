#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
map<pair<ll,ll>,ll> mp;
ll x,y,z;
ll hannuota(ll m,ll A,ll B,ll C){
    if(m==1) return mp[{A,C}];
    ll cnt=0;
    cnt+=hannuota(m-1,A,C,B);
    if(A==1&&C==3||A==3&&C==1) cnt+=z;
    else if(A==1&&C==2||A==2&&C==1) cnt+=x;
    else if(A==2&&C==3||A==3&&C==2) cnt+=y;
    cnt+=hannuota(m-1,B,A,C);
    return cnt;
}
void solve(){
    cin>>n;
    cin>>x>>y>>z;
    mp[{1,2}]=min(x,z+y),mp[{2,3}]=min(y,z+x),mp[{1,3}]=min(z,x+y);
    mp[{2,1}]=mp[{1,2}],mp[{3,2}]=mp[{2,3}],mp[{3,1}]=mp[{1,3}];
    cout<<hannuota(n,1,2,3);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("fakehanoi.in","r",stdin);
    freopen("fakehanoi.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}