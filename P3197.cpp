#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll p=100003;
ll n,m;
ll  qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2) res=res*a%p;
        b/=2;
        a=a*a%p;
    }
    return res;
}
void solve(){
    cin>>m>>n;
    //总数-不越狱数
    ll k=(qpow(m,n)-m*qpow(m-1,n-1)%p)%p;
    if(k<0) k+=p;
    cout<<k%p;
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