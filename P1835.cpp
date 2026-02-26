#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e6+5;
ll l,r,n;
vector<ll> prime;
bool isprime[N];
bool book[N];
void Prime(){
    isprime[1]=isprime[0]=1;
    for(ll i=2;i<=n;i++){
        if(!isprime[i]) prime.push_back(i);
        for(auto j:prime){
            if(i*j>n) break;
            isprime[i*j]=1;
            if(!i%j) break;
        }
    }
}
void solve(){
    cin>>l>>r;
    n=sqrt(r);
    Prime();
    for(auto i:prime){
        ll k=0;
        if(l%i!=0) k=l/i+1;
        else k=l/i;
        for(ll j=k;j*i<=r;j++){
            book[j*i-l]=1;
        }
    }
    ll cnt=0;
    for(int i=0;i<=r-l;i++){
        if(!book[i]) cnt++;
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