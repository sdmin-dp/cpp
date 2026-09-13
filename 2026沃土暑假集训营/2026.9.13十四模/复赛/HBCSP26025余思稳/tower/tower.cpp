#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> w;
ll a[N];
ll dp[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll h,num;
        cin>>h>>a[i]>>num;
        m=min(m,a[i]);
        for(int j=1;j<=num;j*=2){
            w.push_back(h*j);
            num-=j;
        }
        if(num!=0) w.push_back(h*num);
    }
    for(int i=0;i<w.size();i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
        }
    }
    cout<<dp[m];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}