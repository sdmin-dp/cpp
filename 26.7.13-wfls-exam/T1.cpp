#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e7+5;
ll l,r;
bool isprime[N];
vector<ll> prime;
void init(){
    isprime[1]=isprime[0]=1;
    for(ll i=2;i<=r;i++){
        if(!isprime[i]) prime.push_back(i);
        for(auto j:prime){
            if(i*j>r) break;
            isprime[i*j]=1;
            if(!(i%j)) break;
        }
    }
}
void solve(){
    cin>>l>>r;
    init();
    ll ans=0;
    for(int i=l;i<=r;i++){
        if(!isprime[i]) ans+=i;
        else ans++;
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