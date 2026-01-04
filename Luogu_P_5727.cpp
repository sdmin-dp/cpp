#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n;
vector<ll> v;
void solve(){
    cin>>n;
    v.push_back(n);
    while(n!=1){
        if(n%2==1) n=n*3+1;
        else n/=2;
        v.push_back(n);
    }
    reverse(v.begin(),v.end());
    for(auto i:v) cout<<i<<" ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}