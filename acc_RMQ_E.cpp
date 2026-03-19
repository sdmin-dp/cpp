#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
ll n,m,p;
ll ls[N];
ll sum[N];
ll cc[N];
ll lp_idx=-1;
ll ans;
void solve(){
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        ll color,price;
        cin>>color>>price;
        if (price<=p) lp_idx=i;
        if(lp_idx>=ls[color]) sum[color]=cc[color];
        ls[color]=i;
        ans+=sum[color];
        cc[color]++;
    }
    cout<<ans;
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
