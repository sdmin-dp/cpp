#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e6+5;
ll l,r,n;
vector<ll> prime;
bool isprime[N],vis[N];
void init(){
    isprime[0]=isprime[1]=1;
    for(ll i=2;i<=n;i++){
        if(!isprime[i]) prime.push_back(i);
        for(auto j:prime){
            if(j*i>n) break;
            isprime[i*j]=1;
            if(i%j==0) break;
        }
    }
}
void solve(){
    cin>>l>>r;
    n=sqrt(r);
    // vis[1]=1;
    init();
    for(auto i:prime){
        ll k=(l/i);
        if(l%i!=0) k++;
        for(int j=k;i*j<=r;j++){
            vis[i*j]=0;
        }
    }
    ll cnt=0;
    for(int i=1;i<=r-l+1;i++){
        if(!vis[i]) cnt++;
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