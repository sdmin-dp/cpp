#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
vector<pair<ll,ll>> v;
void prime(){
    ll x=n;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            ll cnt=0;
            while(x%i==0){
                cnt++;
                x/=i;
            }
            v.push_back({i,cnt});
        }
    }
    if(x) v.push_back({x,1});
}
void solve(){
    cin>>n;
    prime();
    bool flag=1;
    for(auto i:v){
        if(flag){
            cout<<i.first<<"^"<<i.second;
            flag=0;
        }
        else{
            cout<<"×"<<i.first<<"^"<<i.second;
        }
        
    }
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