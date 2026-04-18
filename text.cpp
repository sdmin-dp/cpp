#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
vector<ll> prime;
bool isprime[N];
ll n;
void init(){
    isprime[0]=isprime[1]=1;
    for(int i=2;i<=n;i++){
        if(!isprime[i]) prime.push_back(i);
        for(auto j:prime){
            if(i*j>n) break;
            isprime[i*j]=1;
            if(!i%j) break;  
        }
    }
}
void solve(){
    cin>>n;
    init();
    for(auto i:prime) if(i>=1000) cout<<i<<" ";
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