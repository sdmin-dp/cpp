#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll cnt[N];
void solve(){
    memset(cnt,0,sizeof(cnt));
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        cnt[a-i]++;
    }
    1
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