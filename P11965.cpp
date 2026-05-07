#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n;
string s;
ll xr[N];
map<ll,ll> mp;
void solve(){
    cin>>n;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        ll k=(1<<(s[i]-'a'));
        xr[i]=xr[i-1]^k;
    }
    ll cnt=0;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        cnt+=mp[xr[i]];
        mp[xr[i]]++;
    }
    cout<<cnt;
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
/*
25个0,1个1->a
24个0,10
*/