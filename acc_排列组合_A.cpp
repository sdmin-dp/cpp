#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
const ll p=10007;
ll a,b,k,n,m;
ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2) res=res*a%p;
        a=a*a%p;
        b/=2;
    }
    return res%p;
}
void init() {
    ll n,k,p;//C(n,k)对p求余
    cin>>n>>k>>p;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0||i==j) Cnk[i][j]=1;
            else Cnk[i][j]=(Cnk[i-1][j-1]+Cnk[i-1][j])%p;
            cout<<Cnk[i][j]<<" ";
        }
        cout<<el;
    }
    cout<<Cnk[n][k];
    return;
}
void solve(){
    cin>>a>>b>>k>>n>>m;
    a%=p;b%=p;
    ll A=qpow(a,n);
    ll B=qpow(b,m);
    out(cnm(k,m)*A*B%p);
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