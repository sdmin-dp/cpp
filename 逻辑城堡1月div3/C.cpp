#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
vector<ll> prime(){
    vector<ll> ans;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            ans.push_back(i);
            n/=i;
        }
    }
    return ans;
}
void solve(){
    cin>>n;
    vector<ll> ans=prime();
    if(ans.size()<=2){
        cout<<"NO";
        return;
    }Z1
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