#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
// const ll N=1e5+5;
ll n;

vector<pair<ll,ll>> prime;
void fjzys(){
    ll x=n;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            ll cnt=0;
            while(x%i==0){
                x/=i;
                cnt++;
            }
            prime.push_back({i,cnt});
        }
    }
    if(x>1) prime.push_back({x,1});
}
void solve(){
    cin>>n;
    prime.clear();
    fjzys();
    ll ans=1,sum=1;
    for(auto i:prime){
        // cerr<<i.first<<" "<<i.second<<el;
        if(i.second%2==1){
            ans*=i.first;
            sum*=(i.second+2);
        }else{
            sum*=(i.second+1);
        }
    }
    cout<<ans<<" "<<sum<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}